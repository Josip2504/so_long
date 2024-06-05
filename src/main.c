/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/05 20:31:41 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac != 2)
		ft_error("Error\nInvalid arguments");
	map_size(&data, av);
	init_map(&data, &map);
	map.map = ft_calloc(data.y + 1, sizeof(char *));
	if (!map.map)
		ft_error("Error\nMemory allocation");
	parse_map(&data, av);
	map_path(&data);
	parse_map(&data, av);
	data.mlx = mlx_init();
	if (!data.mlx)
		ft_error("Error\nProgram init fail");
	data.win = mlx_new_window(data.mlx, data.x, data.y, "./so_long");
	render_game(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	ft_error("Error\nmlx loop fail");
	return (0);
}
