/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:34:52 by bojamee           #+#    #+#             */
/*   Updated: 2021/05/01 15:17:35 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;
	t_list	*current_old;

	if (!lst)
		return (0);
	result = 0;
	current_old = lst;
	while (current_old)
	{
		new = ft_lstnew(current_old->content);
		if (!new)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		new->content = f(current_old->content);
		ft_lstadd_back(&result, new);
		current_old = current_old->next;
	}
	return (result);
}
