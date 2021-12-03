/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:04:11 by tjolivea          #+#    #+#             */
/*   Updated: 2021/11/03 20:09:16 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dup;
	size_t	src_len;

	src_len = ft_strlen(src) + 1;
	dup = malloc((src_len) * sizeof(char));
	if (!dup)
		return (0);
	return (ft_memcpy(dup, src, src_len));
}
