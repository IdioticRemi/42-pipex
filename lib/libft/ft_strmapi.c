/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 06:45:10 by tjolivea          #+#    #+#             */
/*   Updated: 2021/11/04 23:05:03 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dup;

	if (!s)
		return (0);
	i = -1;
	dup = ft_strdup((char *) s);
	if (!dup)
		return (0);
	while (++i < ft_strlen(s))
	{
		dup[i] = f(i, s[i]);
	}
	return (dup);
}
