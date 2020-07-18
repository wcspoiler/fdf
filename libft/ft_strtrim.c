/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 22:43:35 by coclayto          #+#    #+#             */
/*   Updated: 2019/04/28 22:43:38 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	size_t	len;
	size_t	trim;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	if (!s[j])
		return (ft_strnew(0));
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	s1 = (char *)malloc(sizeof(*s1) * (len - j + 1));
	if (!s1)
		return (NULL);
	trim = j;
	while (i < (len - trim))
		s1[i++] = s[j++];
	s1[i] = '\0';
	return (s1);
}
