/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:06:25 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/02 20:06:04 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	counter(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str && str[i])
	{
		if (str[i++] == c)
			count++;
	}
	return (count);
}

static void	map_check(t_data *data)
{
	int	player;
	int	exit;
	int	y;

	player = 0;
	exit = 0;
	y = 0;
	data->map->collectible = 0;
	rec_check(data);
	while (data->map->map && data->map->map[y])
	{
		player += counter(data->map->map[y], 'P');
		exit += counter(data->map->map[y], 'E');
		data->map->collectible += counter(data->map->map[y], 'C');
		y++;
	}
	if (exit != 1)
		ft_error("Error\nMap doesn't contain or has more than one exit");
	if (player != 1)
		ft_error("Error\nMap doesn't contain one player");
	if (data->map->collectible == 0)
		ft_error("Error\nMap has to contain at least one collectible");
}

static void	wall_check(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->y / IMAGE_Y))
	{
		x = 0;
		while (x < (data->x / IMAGE_X))
		{
			if (data->map->map[y][x] != '1' && data->map->map[y][x] != '0' &&
				data->map->map[y][x] != 'P' && data->map->map[y][x] != 'E' &&
				data->map->map[y][x] != 'C')
				ft_error("Error\nMap character are not valid");
			else if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
				ft_error("Error\nMap is not surrounded by walls");
			else if (data->map->map[y][x] != '1'
				&& (y == (data->y / IMAGE_Y - 1)
				|| x == (data->x / IMAGE_X - 1)))
				ft_error("Error\nMap is not surrounded by walls");
			x++;
		}
		y++;
	}
}

void	rec_check(t_data *data)
{
	int	y;
	int	len;

	if (data->map->map[0] == NULL)
		ft_error("Error\nMap is empty");
	len = (int)ft_strlen(data->map->map[0]);
	y = 1;
	while (data->map->map[y])
	{
		if ((int)ft_strlen(data->map->map[y]) != len)
			ft_error("Error\nMap is not rectengular");
		y++;
	}
}

void	parse_map(t_data *data, char **av)
{
	char	*buff;
	int		fd;
	int		i;

	i = 0;
	buff = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpening map");
	while (1)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		if (buff[(int)ft_strlen(buff) - 1] == '\n')
			buff[(int)ft_strlen(buff) - 1] = '\0';
		data->map->map[i] = ft_strdup(buff);
		i++;
		free(buff);
		buff = NULL;
	}
	data->map->map[i] = NULL;
	close(fd);
	map_check(data);
	wall_check(data);
}
