/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:53:16 by tjolivea          #+#    #+#             */
/*   Updated: 2021/11/03 18:36:17 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n-- > 0)
		dest[n] = source[n];
	return (dst);
}
