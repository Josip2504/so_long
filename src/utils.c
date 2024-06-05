/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:06:28 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/04 15:59:27 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

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
int	close_win()
{
	exit(0);
}

int		keypress(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
