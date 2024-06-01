/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:58:12 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/01 20:10:46 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_side(t_data *data, int len)
{
	int	row;

	row = 1;
	while (row < data->map->rows)
	{
		if (data->map->field[row][0] != '1')
			return (0);
		else if (data->map->field[row][len - 1] != '1')
			return (0);
		row++;
	}
	return (1);
}

int	check_walls(t_data *data, int *row, int *col, int len)
{
	*col = 0;
	while (data->map->field[0][*col] != '\n')
	{
		if (data->map->field[0][*col] != '1')
			return (0);
		*col += 1;
	}
	*col = 0;
	*row = data->map->rows - 1;
	while (data->map->field[*row][*col] != '\n' &&
		data->map->field[*row][*col] != '\0')
	{
		if (data->map->field[*row][*col] != '1')
			return (0);
		*col += 1;
	}
	if (!(check_side(data, len)))
		return (0);
	return (1);
}