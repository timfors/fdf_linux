/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:27:30 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/24 23:07:37 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_f;
	char	*src_f;

	i = 0;
	dst_f = (char *)dst;
	src_f = (char *)src;
	if (!dst_f && !src_f)
		return (0);
	while (i < n)
	{
		dst_f[i] = src_f[i];
		i++;
	}
	return (dst);
}
