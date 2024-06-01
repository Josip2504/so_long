/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:39:41 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/01 17:24:13 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_nl(int fd)
{
	int		i;
	int		p;
	char	c;
	ssize_t	b_read;

	i = 1;
	p = '\0';
	if (read(fd, &c, 1) > 0 && c != '1')
		ft_error("Error\nInvalid map");
	while ((b_read = read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
		{
			if (p == '\n')
				ft_error("Error\nInvalid map");
			i++;
		}
		p = c;
	}
	if (p != '1')
		ft_error("Error\nInvalid map");
	return (i);
}
