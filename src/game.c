/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:40:17 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/30 19:43:42 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->exit_col = 0;
	map->exit_row = 0;
	map->num_collectibles = 0;
	map->player_col = 0;
	map->player_row = 0;
}

