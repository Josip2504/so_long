/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/31 16:41:22 by jsamardz         ###   ########.fr       */
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
# define MAX_LINE_LEN 256
# define CHARS "PEC10"

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

// ft_get_nl
char	*ft_get_nl(int fd);

// ft_errors
void	ft_error(char *str);
void	ft_error_msg(int x, t_data *data);
void	ft_free_error(const char *s, t_data *data);

// check_walls
int		check_walls(t_data *data, int *row, int *col, int len);

// check_map
int		check_map(t_data *data);
size_t	ft_nl(char *s);

// utils
int		ft_input(const char *name);
void	ft_free_map(t_data *data);
int		keypress(int keycode);
int		close_win(void);

// game
void	init_map(t_map *map);

// ft_maps
int		read_map(t_data *data, char *file);

#endif