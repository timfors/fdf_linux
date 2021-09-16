/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:30:50 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/24 23:14:33 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dsr, const void *src, size_t len)
{
	size_t	i;
	char	*dsr_f;
	char	*src_f;

	i = 0;
	dsr_f = (char *)dsr;
	src_f = (char *)src;
	if (!dsr_f && !src)
		return (0);
	if (dsr_f > src_f && (size_t)(dsr_f - src_f) < len)
		while (0 < len--)
			dsr_f[len] = src_f[len];
	else
	{
		while (i < len)
		{
			dsr_f[i] = src_f[i];
			i++;
		}
	}
	return (dsr);
}
