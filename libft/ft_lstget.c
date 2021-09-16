/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:45:45 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/23 14:45:47 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *lst, int index)
{
	int		i;
	t_list	*result;

	if (ft_lstsize(lst) <= index)
		return (0);
	i = 0;
	result = lst;
	while (i++ < index)
		result = result->next;
	return (result);
}
