/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:15:34 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/05 20:32:07 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map->map[i] != NULL)
	{
		j = 0;
		while (data->map->map[i][j] != '\0')
		{
			if (data->map->map[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
			}
			else if (data->map->map[i][j] == 'E')
			{
				data->exit_x = i;
				data->exit_y = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill_t(t_data *data, int row, int col, char target)
{
	if (row < 0 || row >= (data->y / IMAGE_Y) || col < 0
		|| col >= (data->x / IMAGE_X))
		return ;
	if (data->map->map[row][col] == '1'
		|| data->map->map[row][col] == target)
		return ;
	data->map->map[row][col] = target;
	flood_fill_t(data, row - 1, col, target);
	flood_fill_t(data, row + 1, col, target);
	flood_fill_t(data, row, col - 1, target);
	flood_fill_t(data, row, col + 1, target);
}

void	flood_fill(t_data *data, int row, int col, char target)
{
	if (row < 0 || row >= (data->y / IMAGE_Y) || col < 0
		|| col >= (data->x / IMAGE_X))
		return ;
	if (data->map->map[row][col] == '1'
		|| data->map->map[row][col] == 'E'
		|| data->map->map[row][col] == target)
		return ;
	data->map->map[row][col] = target;
	flood_fill(data, row - 1, col, target);
	flood_fill(data, row + 1, col, target);
	flood_fill(data, row, col - 1, target);
	flood_fill(data, row, col + 1, target);
}

void	check_new_map(t_data *data, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j] != '\0')
		{
			if (data->map->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count != 0)
		ft_error("Error\nInvalid map path");
}

void	map_path(t_data *data)
{
	char	target;
	char	c;

	target = 'F';
	c = 'C';
	find_player(data);
	flood_fill(data, data->player_x, data->player_y, target);
	check_new_map(data, c);
	target = 'U';
	c = 'E';
	flood_fill_t(data, data->player_x, data->player_y, target);
	check_new_map(data, c);
}
