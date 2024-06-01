/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:40:17 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/01 19:36:37 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_map *map)
{
	map->field = NULL;
	map->rows = 0;
	map->cols = 0;
	map->exit_col = 0;
	map->exit_row = 0;
	map->num_collectibles = 0;
	map->player_col = 0;
	map->player_row = 0;
}
void	get_row_num(t_data *data, char *file)
{
	int	fd;
	int	line;

	line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpenning file");
	line = get_nl(fd);
	data->map->rows = line;
	close(fd);
}
