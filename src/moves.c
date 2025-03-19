/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:07:24 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/05 21:48:49 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	player_move(t_data *data, char p, int dir)
{
	if (p == 'y' && dir == UP)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up,
			(data->player_x * IMAGE_Y), (data->player_y * IMAGE_X));
	}
	if (p == 'y' && dir == DOWN)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_down,
			(data->player_x * IMAGE_Y), (data->player_y * IMAGE_X));
	}
	if (p == 'x' && dir == RIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
			(data->player_x * IMAGE_Y), (data->player_y * IMAGE_X));
	}
	if (p == 'x' && dir == LEFT)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_left,
			(data->player_x * IMAGE_Y), (data->player_y * IMAGE_X));
	}
}

static void	collect(t_data *data, char p, int dir)
{
	data->collected++;
	data->map->map[data->player_y][data->player_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->player_x * IMAGE_Y), (data->player_y * IMAGE_X));
	player_move(data, p, dir);
}

void	moves(t_data *data, char p, int dir)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		(data->player_x * IMAGE_Y), (data->player_y * IMAGE_X));
	if (p == 'y'
		&& data->map->map[data->player_y + 1 * dir][data->player_x] != '1'
		&& (data->map->map[data->player_y + 1 * dir][data->player_x] != 'E'
		|| data->collected == data->map->collectible))
		data->player_y = data->player_y + 1 * dir;
	else if (p == 'x'
		&& data->map->map[data->player_y][data->player_x + 1 * dir] != '1'
		&& (data->map->map[data->player_y][data->player_x + 1 * dir] != 'E'
		|| data->collected == data->map->collectible))
		data->player_x = data->player_x + 1 * dir;
	else if (p == 'y'
		&& data->map->map[data->player_y + 1 * dir][data->player_x] == 'E'
		&& data->collected != data->map->collectible)
		ft_printf("You need to colect all collectibles before exiting\n");
	else if (p == 'x'
		&& data->map->map[data->player_y][data->player_x + 1 * dir] == 'E'
		&& data->collected != data->map->collectible)
		ft_printf("You need to colect all collectibles before exiting\n");
	player_move(data, p, dir);
	if (data->map->map[data->player_y][data->player_x] == 'C')
		collect(data, p, dir);
	mlx_do_sync(data->mlx);
	ft_printf("You moved %d times\n", ++data->moves);
}
