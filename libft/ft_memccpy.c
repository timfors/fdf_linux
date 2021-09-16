/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:46:26 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/24 23:08:00 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dst_f;
	char	*src_f;
	char	c_f;

	i = 0;
	c_f = (char)c;
	dst_f = (char *)dst;
	src_f = (char *)src;
	if (!dst && !src)
		return (0);
	while (i < n && src_f[i] != c_f)
	{
		dst_f[i] = src_f[i];
		i++;
	}
	if (src_f[i] == c_f)
	{
		dst_f[i] = c_f;
		return (dst + i + 1);
	}
	return (0);
}
