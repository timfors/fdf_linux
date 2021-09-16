/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:56:08 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/19 22:25:50 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		len_s1;
	char	*res;

	if (!s1 || !set)
		return (0);
	i = 0;
	len_s1 = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		i++;
	start = i;
	i = 1;
	while (ft_strchr(set, s1[len_s1 - i]))
		i++;
	res = ft_substr(s1, start, len_s1 - start - i + 1);
	return (res);
}
