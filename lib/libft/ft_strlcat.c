/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:05:00 by tjolivea          #+#    #+#             */
/*   Updated: 2021/11/03 18:36:17 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (n < 1)
		return (src_len);
	while (dst[i] && i < n)
		i++;
	while (src[j] && i < n - 1)
		dst[i++] = src[j++];
	if (n >= dst_len)
		dst[i] = '\0';
	if (n < dst_len)
		return (src_len + n);
	else
		return (src_len + dst_len);
}
