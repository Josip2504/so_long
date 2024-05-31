/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:45:10 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/31 15:30:02 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	return (i);
}

static int ft_chars(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->map->rows)
	{
		col = 0;
		while (data->map->field[row][col] != '\n' &&
			data->map->field[row][col] != '\0')
		{
			if (ft_strchr(CHARS, data->map->field == NULL))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

static int	ft_char(t_data *data, char s, int *c)
{
	int	row;
	int	col;

	row = 0;
	*c = 0;
	while (row < data->map->rows)
	{
		col = 0;
		while (row < data->map->field[row][col] != '\0')
		{
			if (data->map->field[row][col] == s)
				*c += 1;
			col++;
		}
		row++;
	}
	if (s == 'P' && (*c > 1 || *c == 0))
		return (0);
	else if (*c == 0)
		return (0);
	return (1);
}

static int	check_char(t_data *data)
{
	int	c;
	if (!(ft_chars(data)))
		return (7);
	if (!(ft_char(data, 'P', &c)))
		return (8);
	if (!(ft_char(data, 'C', &c)))
		return (9);
	if (!(ft_char(data, 'E', &c)))
		return (10);
	else
		data->map->num_collectibles = c;
	return (11);
}

int	check_map(t_data *data)
{
	size_t	len;
	int		x;
	int		row;
	int		col;

	len = ft_nl(data->map->field[0]);
	row = 0;
	while (row < data->map->rows)
	{
		if (len != (ft_nl(data->map->field[0])))
			return (5);
		row++;
	}
	data->map->cols = (int)len;
	if (!(check_walls(data, &row, &col, len)))
		return (6);
	x = check_char(data);
	if (x > 0)
		ft_error_msg(x, data);
	return (11);
}

// 5 - rect
// 6 - wall
// 7 - invalid char
// 8 - player
// 9- col
// 10- exit
// 11 - valid
