/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:36:24 by bojamee           #+#    #+#             */
/*   Updated: 2021/04/27 20:11:06 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static size_t	calc_size(int n)
{
	size_t	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		res++;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static void	iter(char *res, int n, size_t size)
{
	if (n >= 0)
	{
		res[size] = n % 10 + '0';
		if (size == 0)
			return ;
	}
	else
	{
		res[size] = '0' - n % 10;
		if (size == 1)
		{
			res[0] = '-';
			return ;
		}	
	}
	iter(res, n / 10, size - 1);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*res;

	size = calc_size(n);
	res = malloc(size + 1);
	if (!res)
		return (0);
	res[size] = 0;
	iter(res, n, size - 1);
	return (res);
}
