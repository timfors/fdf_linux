/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:48:20 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:45:15 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtoint(const char *str, int start, int end, int *num)
{
	int			i;
	long long	res;

	res = 0;
	i = start - 1;
	while (++i < end)
	{
		res += (str[i] - '0') * ft_pow(10, end - i - 1) * *num;
		if (res > MAX_INT || res < MIN_INT)
			return (-1);
	}
	*num = res;
	return (1);
}

int	ft_atoi_save(const char *str, int *num)
{
	int	res;
	int	start;
	int	end;

	*num = 1;
	start = 0;
	while (str[start] > 0 && str[start] < 33 && str[start] != '\e')
		start++;
	if (str[start] == '+')
		start++;
	else if (str[start] == '-')
	{
		*num = -1;
		start++;
	}
	end = start;
	while (str[end])
	{
		if (!ft_isdigit(str[end]))
			return (-1);
		end++;
	}
	res = ft_strtoint(str, start, end, num);
	return (res);
}
