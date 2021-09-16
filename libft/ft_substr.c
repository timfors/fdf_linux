/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:14:22 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/25 02:32:20 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t max_len)
{
	char			*res;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		len = 0;
	else if (ft_strlen(s) - start < max_len)
		len = ft_strlen(s) - start;
	else
		len = max_len;
	res = malloc(len + 1);
	if (!res)
		return (0);
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
