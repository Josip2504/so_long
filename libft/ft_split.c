/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsamardz <jsamardz@student.42heilnronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:56:56 by jsamardz          #+#    #+#             */
/*   Updated: 2024/03/13 14:59:53 by jsamardz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ftcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = -1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static const char	*process_word(const char *s, char c, char **word)
{
	size_t		wordlen;
	const char	*temp;

	wordlen = 0;
	temp = s;
	while (*temp != c && *temp != '\0')
	{
		wordlen++;
		temp++;
	}
	*word = ft_substr(s, 0, wordlen);
	if (!*word)
		return (NULL);
	return (s + wordlen);
}

static void	ft_free(char **lst, int i)
{
	while (i > 0)
		free(lst[--i]);
	free(lst);
}

char	**ft_split(char const *s, char c)
{
	char		**lst;
	int			i;

	if (!s)
		return (NULL);
	lst = (char **)malloc((ftcount(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			s = process_word(s, c, &lst[i++]);
			if (!lst[i - 1])
			{
				ft_free(lst, i);
				return (NULL);
			}
		}
	}
	lst[i] = NULL;
	return (lst);
}
