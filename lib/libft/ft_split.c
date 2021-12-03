/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 05:43:22 by tjolivea          #+#    #+#             */
/*   Updated: 2021/11/04 23:32:05 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all(char **arr, int i)
{
	while (i > 0)
		free(arr[i--]);
	free(arr);
}

static int	ft_wordcount(char const *s, char c)
{
	int		wc;
	int		i;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			wc++;
		while (s[i] != c && s[i])
			i++;
	}
	return (wc);
}

static char	*ft_create_word(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = ft_calloc(i + 1, 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wc;
	char	**arr;

	if (!s)
		return (0);
	wc = ft_wordcount(s, c);
	arr = ft_calloc(wc + 1, sizeof(char *));
	if (!arr)
		return (0);
	i = -1;
	while (++i < wc)
	{
		while (*s == c)
			s++;
		arr[i] = ft_create_word(s, c);
		if (!arr[i])
		{
			ft_free_all(arr, i);
			return (0);
		}
		s = s + ft_strlen(arr[i]);
	}
	arr[i] = 0;
	return (arr);
}
