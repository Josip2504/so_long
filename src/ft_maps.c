/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:16:37 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/29 16:35:18 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*prase_map(const char *filename, Map* map)
{
	char	line[size];
	int		len;
	FILE	*file = fopen(filename, "r");

	if (!file)
	{
		return "failed to open file";
	}
	// map properties
	map->rows = 0;
	map->cols = 0;
	map->player_col = -1;
	map->player_row = -1;
	map->exit_col = -1;
	map->exit_row = -1;
	map->num_collectibles = 0;
	while (fgets(line, sizeof(line), file))		//fgets
	{
		line[strcspn(line, "\n")] = '\0';		//strcspn
		len = strlen(line);						//strlen
		if (map->cols == 0 )
			map->cols = len;
		else if (len != map->cols)
		{
			fclose(file);
			return "map not rectengular";
		}
		strcpy(map->data[map->rows], line);		//strcpy
		map->rows++;

		// proces char in line
		int j = 0;
		while (j < len)
		{
			char ch = line[j];
			if (ch == 'P')
			{
				if (map->player_row != -1 || map->player_col != -1)
				{
					fclose(file);
					return "dublicate player start pos";
				}
				map->player_row = map->rows -1;
				map->player_col = j;
			}
			else if (ch == 'E')
			{
				if (map->exit_row != -1 || map->exit_col != -1)
				{
					fclose(file);
					return "dublicate exit pos";
				}
				map->player_row = map->rows -1;
				map->player_col = j;
			}
			else if (ch == 'C')
				map->num_collectibles++;
			else if (ch != '0' && ch != '1')
			{
				fclose(file);
				return "invalid char in map";
			}
			j++;
		}
	}
	fclose(file);

	// check required elements
	if (map->player_row == -1 || map->player_col == -1)
		return "player not foud";
	if (map->exit_row == -1 || map->exit_col == -1)
		return "exit not foud";
	if (map->player_row == 0)
		return "collectible not foud";
	
	return ("map prased succesfully");
}
