/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:30:09 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/07 17:37:46 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*point_create(t_vector local_pos, int col, int line)
{
	t_point	*point;

	point = ft_calloc(sizeof(t_point), 1);
	if (!point)
		return (0);
	point->local_pos = local_pos;
	point->col = col;
	point->line = line;
	return (point);
}

void	point_connect(t_object object, t_point	*point)
{
	t_list	*connection;

	connection = object_get(object, point->col, point->line - 1);
	if (connection)
	{
		connection = ft_lstnew(connection->content);
		if (!connection)
			print_err("No memory!\n");
		ft_lstadd_front(&point->connected, connection);
	}
	connection = object_get(object, point->col - 1, point->line);
	if (connection)
	{
		connection = ft_lstnew(connection->content);
		if (!connection)
			print_err("No memory!\n");
		ft_lstadd_front(&point->connected, connection);
	}
}
