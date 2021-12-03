/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:38:42 by tjolivea          #+#    #+#             */
/*   Updated: 2021/11/03 19:56:21 by tjolivea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	x;
	int	sign;

	x = 0;
	sign = 1;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == ' '))
		nptr++;
	if (*nptr && !ft_isdigit(*nptr))
	{
		sign *= ((*nptr == '+') * 1) + ((*nptr == '-') * -1);
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
		x = x * 10 + (*nptr++ - '0');
	return (sign * x);
}
