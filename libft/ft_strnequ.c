/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:41:39 by coclayto          #+#    #+#             */
/*   Updated: 2019/04/28 22:41:42 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 && s2)
	{
		while (i < n && s1[i] == s2[i] && (s1[i] && s2[i]))
		{
			if (s1[i] == s2[i])
				i++;
		}
		if (i == n || (!s1[i] && !s2[i]))
			return (1);
	}
	return (0);
}
