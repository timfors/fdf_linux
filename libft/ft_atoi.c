/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:48:20 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:44:56 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_pow(int num, int size)
{
	int			i;
	long long	res;

	i = -1;
	res = 1;
	while (++i < size)
		res *= num;
	return (res);
}

static int	ft_strtoint(const char *str, int start, int end)
{
	int	i;
	int	res;

	res = 0;
	i = start - 1;
	while (++i < end)
		res += (str[i] - '0') * (int)ft_pow(10, end - i - 1);
	return (res);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	start;
	int	end;
	int	multipl;

	start = 0;
	multipl = 1;
	while (str[start] > 0 && str[start] < 33 && str[start] != '\e')
		start++;
	if (str[start] == '+')
		start++;
	else if (str[start] == '-')
	{
		multipl = -1;
		start++;
	}
	end = start;
	while (ft_isdigit(str[end]))
		end++;
	if (end - start > 19)
		return ((1 + multipl) / -2);
	res = ft_strtoint(str, start, end);
	if (res < 0)
		return (res);
	return (res * multipl);
}
