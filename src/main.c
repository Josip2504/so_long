/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:22 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/29 16:26:21 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define KEY_ESC 53

int close_win()
{
	exit (0);
}

int keypress(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	const char	*filename = "map.ber";
	Map map;
	char *result;
	
	result = prase_map(filename, &map);
	printf("%s\n", result);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Game");
	mlx_hook(win_ptr, 2, 0, keypress, NULL);
	mlx_hook(win_ptr, 17, 0, close_win, NULL);
	mlx_loop(mlx_ptr);
	return 0;
}
