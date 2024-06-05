/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:59:31 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/05 21:53:56 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	game_over(void)
{
	ft_printf("You won!");
	exit(EXIT_SUCCESS);
}

static void	load_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->y / IMAGE_X))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			load_player(data);
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			load_obj(data, "./img/exit.xpm");
		else if (data->map->map[data->map->y][data->map->x] == '1')
			load_obj(data, "./img/wall.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			load_obj(data, "./img/col.xpm");
		if (data->map->x < (data->x / IMAGE_Y))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		esc_game(data);
	else if (keycode == W)
		moves(data, 'y', UP);
	else if (keycode == A)
		moves(data, 'x', LEFT);
	else if (keycode == S)
		moves(data, 'y', DOWN);
	else if (keycode == D)
		moves(data, 'x', RIGHT);
	if (data->map->map[data->player_y][data->player_x] == 'E')
		game_over();
	return (0);
}

int	esc_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("You exit game");
	free_data(data);
	exit(EXIT_SUCCESS);
}

void	render_game(t_data *data)
{
	background(data);
	load_map(data);
	mlx_hook(data->win, 17, 1L << 2, esc_game, data);
}
