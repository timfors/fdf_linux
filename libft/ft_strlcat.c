/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:34:45 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/24 23:37:37 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	i;
	size_t	tmp;

	start = ft_strlen(dst);
	i = 0;
	tmp = ft_strlen(src);
	if (!dstsize || dstsize < start)
		return (dstsize + tmp);
	while (i + start < dstsize - 1 && src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[start + i] = 0;
	return (start + tmp);
}
