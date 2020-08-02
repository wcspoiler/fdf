/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 22:53:04 by releanor          #+#    #+#             */
/*   Updated: 2020/06/27 23:25:55 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


#include <stdio.h>


int		get_width(int fd)
{
	int 	width;
	char 	*line;
	char	**line2;
	int 	i;
	
	width = 0;
	i = 	0;
	get_next_line(fd, &line);



	line2 = ft_strsplit(line, ' ');
	while (line2[width])
		width++;
	free(line);
	while (i < width)
	{
		free(line2[i]);
		i++;
	}
	free(line2);
	return (width);
}

int		get_height(int fd)
{
	int height;
	char *line;

	// line = NULL;
	height = 0;
	while (get_next_line(fd, &line))
		height++;
	free(line);
	return (height + 1);
}

int		get_z(t_map *map)
{
	int i;
	int j;
	int	k;
	int fd;
	char *line;
	char **line2;

	i = 0;
	j = 0;
	k = 0;
	fd = open(map->file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		// free(line);
		k = 0;
		while (line2[k])
			free(line2[k++]);
		free(line2);
		line2 = ft_strsplit(line, ' ');
		j = 0;
		while (line2[j])
		{
			map->z_index[i][j] = ft_atoi(line2[j]);
		//	printf("%sT     ", line2[j]);
			j++;
		}
		// map->z_index[i][j] = NULL;
		i++;
	}
	map->z_index[i] = NULL;

	j = 0;
	// while (line2[j])
	// 	free(line2[j++]);
	// free(line2);
	
// TEST MAP PRINT
	// i = 0;
	// j = 0;
	// while (i < map->height)
	// {
	// 	j = 0;
	// 	while (j < map->width)
	// 	{
	// 		printf("%3d  |", map->z_index[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// free(line);




	return (0);
}

int		open_file(t_map *map)
{
	int fd = 0;
	int i;

	i = 0;
	fd = open(map->file_name, O_RDONLY);

	map->width = get_width(fd);
	map->height = get_height(fd);

	map->z_index = (int **)malloc(sizeof(int *) * (map->height + 1));
	while (i <= map->height)
		map->z_index[i++] = (int *)malloc(sizeof(int) * (map->width + 1));
	get_z(map);

	printf("%d  %d\n", map->width, map->height);

	return (0);
}



	// printf("TEST\n");
	// while (get_next_line(fd, &line))
	// {
	// 	printf("%3s\n", line);
	// }