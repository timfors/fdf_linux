/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:34:57 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/24 23:25:13 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*res;
	size_t	i;

	res = (char *)s;
	i = 0;
	while (i < n && res[i] != c)
		i++;
	if (i < n)
		return (res + i);
	return (0);
}
