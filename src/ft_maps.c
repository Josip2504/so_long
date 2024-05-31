/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:16:37 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/31 16:09:12 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_row_num(t_data *data, char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpenning file");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map->rows += 1;
		free(line);
		line = NULL;
	}
	close(fd);
}

static void	parse_map(const char *file, t_data *data)
{
	int		rows;
	int		fd;
	char	*line;

	line = NULL;
	rows = data->map->rows;
	data->map->field = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!data->map->field)
		ft_error("Error\nMemory allocation");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpening file");
	rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		data->map->field[rows] = ft_strdup(line);
		rows++;
		free(line);
		line = NULL;
	}
	data->map->field[rows] = 0;
	close(fd);
}

int	read_map(t_data *data, char *file)
{
	int	check;

	get_row_num(data, file);
	ft_printf("rows = %d\n", data->map->rows);
	if (data->map->rows == 0)
		ft_error("Error\nNo map");
	parse_map(file, data);
	check = check_map(data);
	if (check > 0)
		ft_error("Error\nInvalid map");
	return (0);
}
