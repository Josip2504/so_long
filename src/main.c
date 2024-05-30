/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/30 22:14:48 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (ft_error("Error\nInvalid arguments"));
	if (!ft_input(av[1]))
		return (ft_error("Error\nArgument must be .ber file"));
	ft_bzero(&data, sizeof(t_data));
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		ft_error("Error\nMemory allocation");
	init_map(data->map);
	read_map(&data, av[1]);
	return (0);
}

// mlx_ptr = mlx_init();
// win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Game");
// mlx_hook(win_ptr, 2, 0, keypress, NULL);
// mlx_hook(win_ptr, 17, 0, close_win, NULL);
// mlx_loop(mlx_ptr);