/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:50:54 by tjolivea          #+#    #+#             */
/*   Updated: 2021/12/10 11:57:06 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *error_msg)
{
	if (!error_msg)
		ft_putendl_fd("ERROR: No error message provided.", 2);
	else
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putendl_fd(error_msg, 2);
	}
	exit(1);
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	*path_str;
	char	**path;
	char	*loc;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path_str = env[i] + 5;
	path = ft_split(path_str, ':');
	i = 0;
	while (path && path[i])
	{
		loc = ft_pathjoin(path[i], cmd);
		if (!access(loc, F_OK))
		{
			ft_afree(path);
			return (loc);
		}
		free(loc + (0 * i++));
	}
	ft_afree(path);
	return (cmd);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**cmd_argv;
	char	*path;

	cmd_argv = ft_split(cmd, ' ');
	if (cmd_argv && cmd_argv[0])
	{
		if (ft_strchr(cmd_argv[0], '/'))
			path = cmd_argv[0];
		else
			path = get_cmd_path(cmd_argv[0], env);
		execve(path, cmd_argv, env);
	}
	ft_afree(cmd_argv);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd("Path to executable not found for command: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(".", 2);
	exit(1);
}

void	exec_child(int file_in, char *cmd, char **env)
{
	pid_t	pid;
	int		files[2];

	if (pipe(files) < 0)
		ft_exit("Pipe error.");
	pid = fork();
	if (pid < 0)
		ft_exit("Fork error.");
	if (pid)
	{
		close(files[1]);
		dup2(files[0], STDIN_FILENO);
		return ;
	}
	close(files[0]);
	dup2(files[1], STDOUT_FILENO);
	if (file_in == STDIN_FILENO)
		exit(1);
	exec_cmd(cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	int	file_in;
	int	file_out;
	int	i;

	if (argc != 5)
		ft_exit("Usage: ./pipex file_in cmd_1 cmd_2 file_out.");
	file_in = open(argv[1], O_RDONLY);
	if (file_in < 0)
		ft_exit("Couldn't open input file.");
	file_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file_out < 0)
		ft_exit("Couldn't open output file.");
	dup2(file_in, STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	i = 1;
	while (++i < argc - 2)
		exec_child(file_in, argv[i], env);
	exec_cmd(argv[argc - 2], env);
	return (0);
}
