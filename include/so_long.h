/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/30 22:15:25 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define MAX_MAP_SIZE 100
# define KEY_ESC 53

typedef struct s_map
{
	char	**field;
	int		rows;
	int		cols;
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;
	int		num_collectibles;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	t_map	*map;
}	t_data;

// check_map
int	check_map(t_data *data);

// utils
int		ft_error(char *str);
int		ft_input(const char *name);
void	free_map(t_map *map);
int		keypress(int keycode);
int		close_win(void);

// game
void	init_map(t_map *map);

// ft_maps
int		read_map(t_data *data, char *file);

#endif