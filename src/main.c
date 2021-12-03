/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:50:54 by tjolivea          #+#    #+#             */
/*   Updated: 2021/12/03 18:14:33 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_substr(path, ft_strichr(path, ':') + 1,
				ft_strichr((ft_strchr(path, ':') + 1), ':'));
		bin = ft_pathjoin(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (cmd);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**cmd_argv;
	char	*path;

	cmd_argv = ft_split(cmd, ' ');
	if (ft_strchr(cmd_argv[0], '/'))
		path = cmd_argv[0];
	else
		path = get_cmd_path(cmd_argv[0], env);
	execve(path, cmd_argv, env);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
	exit(127);
}

void	exec_pre(int file_in, char *cmd, char **env)
{
	pid_t	pid;
	int		files[2];

	pipe(files);
	pid = fork();
	if (pid)
	{
		close(files[1]);
		dup2(files[0], 0);
		waitpid(pid, NULL, 0);
		return ;
	}
	close(files[0]);
	dup2(files[1], 1);
	if (file_in == 0)
		exit(1);
	else
		exec_cmd(cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	int	file_in;
	int	file_out;

	if (argc == 5)
	{
		file_in = open(argv[1], O_RDONLY);
		file_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (file_in < 0 || file_out < 0)
		{
			ft_putendl_fd("File open error!", 2);
			return (-1);
		}
		dup2(file_in, 0);
		dup2(file_out, 1);
		exec_pre(file_in, argv[2], env);
		exec_cmd(argv[3], env);
	}
	else
		ft_putendl_fd("Invalid arg count!", 2);
	return (0);
}
