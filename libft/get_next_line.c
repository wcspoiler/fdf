/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 06:37:14 by releanor          #+#    #+#             */
/*   Updated: 2019/11/27 06:37:19 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_offset(const char *str, int chr)
{
	size_t			offset;
	unsigned char	c;

	offset = 0;
	c = (unsigned char)chr;
	while (str[offset] != c && str[offset] != '\0')
		offset++;
	return (offset);
}

static void		str_joint(char **work_str, char *buff, int fd)
{
	char	*tmp;

	tmp = ft_strjoin(work_str[fd], buff);
	free(work_str[fd]);
	work_str[fd] = tmp;
}

static int		out_line(char **line, char **work_str, int fd)
{
	char	*tmp;
	size_t	offset;

	if (ft_strchr(work_str[fd], '\n') != NULL)
	{
		offset = ft_offset(work_str[fd], '\n');
		free(line);
		*line = ft_strsub(work_str[fd], 0, offset);
		tmp = ft_strdup(work_str[fd] + offset + 1);
		free(work_str[fd]);
		work_str[fd] = tmp;
		if (work_str[fd][0] == '\0')
			ft_strdel(&work_str[fd]);
	}
	else
	{
		*line = ft_strdup(work_str[fd]);
		ft_strdel(&work_str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*work_str[FD_MAX];
	char			buff[BUFF_SIZE + 1];
	int				bytes;

	if (BUFF_SIZE < 1 || fd < 0 || NULL == line || fd > FD_MAX)
		return (-1);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (!work_str[fd])
			work_str[fd] = ft_strnew(0);
		str_joint(work_str, buff, fd);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && !work_str[fd])
		return (0);
	return (out_line(line, work_str, fd));
}
