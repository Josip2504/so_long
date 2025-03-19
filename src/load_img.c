/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:20:40 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/05 01:54:47 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img->background,
				x, y);
			x += IMAGE_Y;
		}
		y += IMAGE_X;
	}
}

void	load_obj(t_data *data, char *path)
{
	int	x;
	int	y;

	data->map->obj = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
	mlx_put_image_to_window(data->mlx, data->win, data->map->obj,
		(data->map->x * IMAGE_Y), (data->map->y * IMAGE_X));
}

void	load_player(t_data *data)
{
	data->player_x = data->map->x;
	data->player_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
		(data->map->x * IMAGE_Y), (data->map->y * IMAGE_X));
}
