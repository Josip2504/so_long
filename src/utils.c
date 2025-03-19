/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:06:28 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/05 21:43:55 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	counter(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str && str[i])
	{
		if (str[i++] == c)
			count++;
	}
	return (count);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map)
	{
		while (data->map->map[i])
		{
			free(data->map->map[i]);
			i++;
		}
		free(data->map->map);
	}
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
