/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:56:25 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/24 23:15:02 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charcomp(unsigned char c1, unsigned char c2)
{
	if (c1 > c2)
		return (1);
	else if (c1 < c2)
		return (-1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (s1[i] && s2[i] && i < n)
	{
		res = charcomp(s1[i], s2[i]);
		if (res)
			return (res);
		i++;
	}
	if (i < n)
		res = charcomp(s1[i], s2[i]);
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (s1[i] && s2[i])
	{
		res = charcomp(s1[i], s2[i]);
		if (res)
			return (res);
		i++;
	}
	res = charcomp(s1[i], s2[i]);
	return (res);
}
