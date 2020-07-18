/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:19:50 by coclayto          #+#    #+#             */
/*   Updated: 2019/04/28 22:43:27 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (start < slen)
	{
		substr = (char *)malloc(sizeof(*substr) * (len + 1));
		if (!substr)
			return (NULL);
		while (s[start] && i < len)
			substr[i++] = s[start++];
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
