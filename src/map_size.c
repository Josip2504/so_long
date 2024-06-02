/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:39:18 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/02 18:15:29 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	lenght(int fd)
{
	char	buff[1];
	int		len;
	int		b;

	buff[0] = '\0';
	len = 0;
	b = 1;
	while (b == 1)
	{
		b = read(fd, buff, 1);
		if (buff[0] != '\n')
			len++;
		else
			break ;
	}
	return (len);
}

int	lines(int fd, int x, int img)
{
	char	*line;
	int		lc;
	int		i;

	lc = 1;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / img
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			ft_error("Error\nMap is not rectengular");
		}
		else
		{
			free(line);
			lc++;
		}
	}
	return (lc);
}

void	map_size(t_data *data, char **av)
{
	int	fd;

	if (!ft_input(av[1]))
		ft_error("Error\nArgument must be .ber file");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nOpening map, check does map exits");
	data->x = (lenght(fd) * IMAGE_X);
	data->y = (lines(fd, data->x, IMAGE_Y) * IMAGE_X);
}
