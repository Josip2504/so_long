/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:15:34 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/03 23:11:13 by jsamardz         ###   ########.fr       */
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

int	flood_fill(t_data *data, int row, int col, int count_e)
{
	char	original;

	if (row < 0 || row >= (data->x / IMAGE_X) || col < 0
		|| col >= (data->y / IMAGE_Y)
		|| data->map->map[row][col] == '1'
		|| data->map->map[row][col] == '2')
		return (count_e);
	original = data->map->map[row][col];
	if (original == 'E')
		count_e++;
	data->map->map[row][col] = '2';
	count_e = flood_fill(data, row - 1, col, count_e);
	count_e = flood_fill(data, row + 1, col, count_e);
	count_e = flood_fill(data, row, col - 1, count_e);
	count_e = flood_fill(data, row, col + 1, count_e);
	data->map->map[row][col] = original;
	return (count_e);
}

void	map_path(t_data *data)
{
	int		count_e;

	count_e = 0;
	find_player(data);
	count_e = flood_fill(data, data->player_x, data->player_y, count_e);
	if (count_e < 1)
		ft_error("Error\nNo path to exit");
}
