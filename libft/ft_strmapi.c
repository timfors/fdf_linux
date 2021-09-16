/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:16:43 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/27 20:22:14 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	size;
	unsigned int	i;

	if (!s)
		return (0);
	size = ft_strlen(s);
	res = malloc(size + 1);
	if (!res)
		return (0);
	res[size] = 0;
	i = 0;
	while (i < size)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
