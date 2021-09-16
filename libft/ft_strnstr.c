/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:52:10 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/24 23:12:06 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*res;
	size_t	index;
	size_t	needle_len;

	if (!needle && !haystack)
		return (0);
	index = 0;
	res = (char *)haystack;
	if (!needle[0])
		return (res);
	needle_len = ft_strlen(needle);
	while (index < len && haystack[index] && len - index >= needle_len)
	{
		if (ft_strncmp(res + index, needle, needle_len) == 0)
			return (res + index);
		index++;
	}
	return (0);
}
