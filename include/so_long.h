/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/03 15:23:22 by jsamardz         ###   ########.fr       */
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

# define IMAGE_X 32
# define IMAGE_Y 32

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		collectible;
	void	*player;
	t_pos	start;
	t_pos	end;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		moves;
	int		collected;
	t_map	*map;
	t_pos	current;
}	t_data;

// utils
void	free_array(char **s);

// map_path


// input
int		ft_input(const char *name);

// map_size
void	map_size(t_data *data, char **av);

// error
void	ft_error(char *str);
int		counter(char *str, char c);

// parse_map
void	parse_map(t_data *data, char **av);
void	rec_check(t_data *data);

#endif