/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/05 21:45:28 by jsamardz         ###   ########.fr       */
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

# define KEY_ESC 53
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1
# define W 13
# define A 0
# define S 1
# define D 2

# define IMAGE_X 64
# define IMAGE_Y 64

typedef struct s_img
{
	void	*background;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		collectible;
	void	*obj;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	int		moves;
	int		collected;
	t_map	*map;
	t_img	*img;
}	t_data;

// init_map
void	init_map(t_data *data, t_map *map);

// moves
void	moves(t_data *data, char p, int dir);

// render_game
void	render_game(t_data *data);
int		esc_game(t_data *data);
int		key_hook(int keycode, t_data *data);

// load_img
void	background(t_data *data);
void	load_obj(t_data *data, char *path);
void	load_player(t_data *data);

// utils
int		counter(char *str, char c);
void	free_data(t_data *data);
void	ft_error(char *str);

// map_path
void	map_path(t_data *data);

// input
int		ft_input(const char *name);

// map_size
void	map_size(t_data *data, char **av);

// parse_map
void	parse_map(t_data *data, char **av);
void	rec_check(t_data *data);

#endif