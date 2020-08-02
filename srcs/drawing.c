/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 22:53:04 by releanor          #+#    #+#             */
/*   Updated: 2020/06/27 23:25:55 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	get_max(float x, float y)
{
	return ((x > y) ? x : y);
}

float	get_abs(float x)
{
	return ((x > 0) ? x : -x);
}

void	isometric(float *x, float *y, int z, t_map *map)
{
	*x = (*x - *y) * cos(map->fi);
	*y = (*x + *y) * sin(-map->fi) - z;
}

void	bresenham(float x0, float y0, float x, float y, t_map *map)
{
	int max;
	int z0;
	int z;
	float x_step;
	float y_step;


	z0 = map->z_index[(int)y0][(int)x0];
	z = map->z_index[(int)y][(int)x];

	x0 *= map->zoom;
	y0 *= map->zoom;
	x *= map->zoom;
	y *= map->zoom;



	map->color = (z0 || z) ? 0xff0000 : 0xffffff;


	isometric(&x0, &y0, z0, map);
	isometric(&x, &y, z, map);

	x0 += 200;
	y0 += 200;
	x += 200;
	y += 200;

	x0 += map->shift_x;
	y0 += map->shift_y;
	x += map->shift_x;
	y += map->shift_y;


	x_step = x - x0;
	y_step = y - y0;

	max = get_max(get_abs(x_step), get_abs(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(x0 - x) || (int)(y0 - y))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x0, y0, map->color);
		x0 += x_step;
		y0 += y_step;
	}
}

void	draw(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				bresenham(x, y, x + 1, y, map);
			if (y < map->height - 1)
				bresenham(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}