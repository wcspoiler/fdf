/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 22:53:04 by releanor          #+#    #+#             */
/*   Updated: 2020/06/27 23:25:55 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fdf.h"

int		deal_key(int key, t_map *map)
{
	printf("%d\n", key);

	if (key == 126)
		map->shift_y -= 10;
	else if (key == 125)
		map->shift_y += 10;
	else if (key == 123)
		map->shift_x -= 10;
	else if (key == 124)
		map->shift_x += 10;
	else if (key == 12)
		map->fi -= 0.1;
	else if (key == 14)
		map->fi += 0.1;
	else if (key == 27 && map->zoom > 0)
		map->zoom -= 1;
	else if (key == 24)
		map->zoom += 1;
	else
		return (0);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		printf("SASAT");
		return (1);
	}


	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	
	map->file_name = argv[1];

	open_file(map);

	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "KEKK");

	map->zoom = 20;
	map->fi = 0.8;

	//bresenham(10, 10, 1000, 1000, map);

	draw(map);

	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);

	return (0);
}