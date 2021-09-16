/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:46:51 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/25 00:50:55 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		s1_len;

	s1_len = ft_strlen(s1);
	res = malloc(s1_len + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, s1, s1_len + 1);
	return (res);
}
