/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:28:04 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/09 13:55:56 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_y(int x, t_vector start, t_vector end)
{
	return ((x - start.x) * (end.y - start.y) / (end.x - start.x) + start.y);
}

int	get_x(int y, t_vector start, t_vector end)
{
	return ((y - start.y) * (end.x - start.x) / (end.y - start.y) + start.x);
}

int	optimize_point_y(t_vector *start, t_vector *end, t_data data)
{
	t_vector	new_start;

	new_start = vector_create(get_x(0, *start, *end), 0, 0);
	if (start->y < 0 && (new_start.x < 0 || new_start.x >= data.width))
		return (0);
	else if (start->y < 0)
		*start = new_start;
	new_start = vector_create(get_x(data.height - 1, *start, *end),
			data.height - 1, 0);
	if (start->y >= data.height && (new_start.x < 0
			|| new_start.x >= data.width))
		return (0);
	else if (start->y >= data.height)
		*start = new_start;
	return (1);
}

int	optimize_point_x(t_vector *start, t_vector *end, t_data data)
{
	t_vector	new_start;

	new_start = vector_create(0, get_y(0, *start, *end), 0);
	if (start->x < 0)
		*start = new_start;
	new_start = vector_create(data.width - 1,
			get_y(data.width - 1, *start, *end), 0);
	if (start->x >= data.width)
		*start = new_start;
	return (1);
}
