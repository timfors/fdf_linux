/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:52:11 by bojamee           #+#    #+#             */
/*   Updated: 2021/05/10 15:08:49 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_elems(char const *str, char c)
{
	size_t	res;
	int		i;

	i = 0;
	while (str[i] == c && str[i])
		i++;
	if (!str[i])
		return (0);
	res = 1;
	while (str[++i])
	{
		if (str[i] == c)
		{
			while (str[++i] == c)
				;
			if (!str[i])
				return (res);
			res++;
		}
	}
	return (res);
}

static void	clear(char **matrix, int count)
{
	while (count >= 0)
		free(matrix[count--]);
	free(matrix);
}

static void	find_next(const char *str, char c, int *start, int *end)
{
	while (str[(*start)++] == c)
		;
	*end = (*start)--;
	while (str[*end] != c && str[*end])
		(*end)++;
}

static int	divide(char **res, const char *str, char c, int elem_size)
{
	int	start;
	int	end;
	int	cur;

	start = 0;
	cur = 0;
	end = start;
	while (cur < elem_size)
	{
		find_next(str, c, &start, &end);
		res[cur] = ft_substr(str, start, end - start);
		if (!res[cur])
		{
			clear(res, cur - 1);
			return (0);
		}
		cur++;
		start = end;
	}
	res[cur] = 0;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	int		elem_size;

	if (!str)
		return (0);
	elem_size = count_elems(str, c);
	res = malloc((elem_size + 1) * sizeof(char *));
	if (!res)
		return (0);
	if (!divide(res, str, c, elem_size))
		return (0);
	return (res);
}
