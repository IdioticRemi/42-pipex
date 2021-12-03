/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:43:10 by tjolivea          #+#    #+#             */
/*   Updated: 2021/11/03 19:14:03 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sc1;
	const unsigned char	*sc2;

	sc1 = (const unsigned char *) s1;
	sc2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*sc1 != *sc2)
			return (*sc1 - *sc2);
		sc1++;
		sc2++;
	}
	return (0);
}
