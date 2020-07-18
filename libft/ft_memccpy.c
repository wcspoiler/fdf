/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:34:51 by coclayto          #+#    #+#             */
/*   Updated: 2019/04/28 22:34:54 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (n)
	{
		*s1 = *s2;
		if (*s1 == (unsigned char)c)
		{
			*s1 = *s2;
			return (s1 + 1);
		}
		s1++;
		s2++;
		n--;
	}
	return (NULL);
}
