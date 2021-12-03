/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:02:25 by tjolivea          #+#    #+#             */
/*   Updated: 2021/11/03 18:53:29 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = -1;
	s_len = ft_strlen(s);
	if (!c)
		return ((char *)s + s_len);
	while (++i < s_len)
		if (s[i] == (char) c)
			return ((char *)s + i);
	return (0);
}
