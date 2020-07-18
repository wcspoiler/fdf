/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 22:53:04 by releanor          #+#    #+#             */
/*   Updated: 2020/06/27 23:25:55 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <math.h>
#include "../libft/includes/libft.h"
#include "../minilibx_macos/mlx.h"

typedef	struct	s_struct
{
	char	*file_name;
	int		width;
	int		height;
	int		**z_index;
	void	*win_ptr;
	void	*mlx_ptr;
	int		shift_x;
	int		shift_y;
	int		z;
	float	fi;
	int		zoom;
	int		color;
}				t_map;

// typedef struct 	s_struct
// {
	
// }				t_point;


int		open_file(t_map *map);
int		get_width(int fd);
int		get_height(int fd);
int		get_z(t_map *map);

void	bresenham(float x0, float y0, float x, float y, t_map *map);
float	get_max(float x, float y);
float	get_abs(float x);
void	draw(t_map *map);

int		deal_key(int key, t_map *map);

#endif