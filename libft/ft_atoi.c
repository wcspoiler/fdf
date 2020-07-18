/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 04:49:54 by coclayto          #+#    #+#             */
/*   Updated: 2019/04/27 04:50:06 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *nptr)
{
	size_t		i;
	long int	sign;
	long int	res;
	int			temp;

	i = 0;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = (nptr[i] == '-') ? -1 : 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		temp = res;
		res = res * 10 + (nptr[i] - '0');
		i++;
		if (sign > 0 && res < temp)
			return (-1);
		if (sign < 0 && (sign * res) > temp)
			return (0);
	}
	return (sign * res);
}
