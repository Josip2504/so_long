/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:16 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/29 16:16:17 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx/mlx.h"
#include <stdio.h>
#include <string.h>

#define size 100

// maps
typedef struct
{
	char	data[size][size];
	int		rows;
	int		cols;
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;
	int		num_collectibles;
} Map;

char	*prase_map(const char *filename, Map* map);

// export DYLD_LIBRARY_PATH=/Users/jsamardz/Desktop/so_long/mlx:$DYLD_LIBRARY_PATH