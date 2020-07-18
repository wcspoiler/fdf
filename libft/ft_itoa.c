/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:33:26 by coclayto          #+#    #+#             */
/*   Updated: 2020/03/01 10:50:57 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	str_len(long long n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(long long n)
{
	char			*str;
	size_t			len;
	long long		n1;

	len = str_len(n);
	n1 = n;
	if (n < 0)
	{
		n1 = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n1 % 10 + '0';
	while (n1 /= 10)
		str[--len] = n1 % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
