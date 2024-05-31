/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:30:28 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/31 15:40:47 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_error(const char *s, t_data *data)
{
	ft_free_map(data);
	free(data->map);
	ft_printf("%s\n", s);
	exit(EXIT_FAILURE);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	ft_error_msg(int x, t_data *data)
{
	if (x == 5)
		ft_free_error("Error\nMap not rectengular", data);
	else if (x == 6)
		ft_free_error("Error\nInvalid walls", data);
	else if (x == 7)
		ft_free_error("Error\nInvalid chars", data);
	else if (x == 8)
		ft_free_error("Error\nInvalid player position", data);
	else if (x == 9)
		ft_free_error("Error\nNo collectibles", data);
	else if (x == 10)
		ft_free_error("Error\nNo exit", data);
}

// 5 - rect
// 6 - wall
// 7 - invalid char
// 8 - player
// 9- col
// 10- exit
// 11 - valid