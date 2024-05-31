/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:39:41 by jsamardz          #+#    #+#             */
/*   Updated: 2024/05/31 16:55:10 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_get_nl(int fd)
{
	static char buf[BUFFER_SIZE + 1];
    char *line = NULL;
    char *tmp;
    int ret;
    int i;

    line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (line == NULL)
        return (NULL);
    tmp = line;
    while ((ret = read(fd, buf, BUFFER_SIZE)) > 0) {
        buf[ret] = '\0';
        for (i = 0; buf[i] != '\0' && buf[i] != '\n'; i++)
            *tmp++ = buf[i];
        if (buf[i] == '\n') {
            *tmp = '\0';
            return (line);
        }
    }
    if (ret == 0 && tmp != line)
        return (line);
    free(line);
    return (NULL);
}
