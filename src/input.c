/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:41:24 by jsamardz          #+#    #+#             */
/*   Updated: 2024/06/02 13:33:40 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_input(const char *name)
{
	const char	*end;
	size_t		len_name;
	size_t		len_end;
	size_t		res;

	end = ".ber";
	len_name = ft_strlen(name);
	len_end = ft_strlen(end);
	if (len_name < len_end)
		return (0);
	res = ft_strncmp(name + len_name - len_end, end, 4) == 0;
	return (res);
}
