/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/02 19:47:22 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_data *data, t_map *map)
{
	data->map = map;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac != 2)
		ft_error("Error\nInvalid arguments");
	map_size(&data, av);
	init_map(&data, &map);
	data.map->map = (char **)malloc(sizeof(char *) * (data.map->y + 1));
	if (!data.map->map)
		ft_error("Error\nMemory allocation");
	parse_map(&data, av);
	printf("paresed");
	return (0);
}
