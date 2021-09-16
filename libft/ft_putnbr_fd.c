/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:37:05 by bojamee           #+#    #+#             */
/*   Updated: 2021/05/05 16:54:05 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	iter(int n, int fd)
{
	if (n > 0)
	{
		if (n >= 10)
			iter(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n <= -10)
			iter(-(n / 10), fd);
		ft_putchar_fd('0' - n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		iter(n, fd);
}
