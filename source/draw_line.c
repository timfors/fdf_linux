/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 15:26:18 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/09 13:58:29 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	draw_point(int x, int y, t_data *data)
{
	int	size;
	int	sized_x;
	int	sized_y;

	size = LINE_SIZE;
	while (size)
	{
		sized_y = y + size - (size % 2) - LINE_SIZE / 2;
		sized_x = x + size - (size % 2) - LINE_SIZE / 2;
		if (y >= 0 && y < data->height && x >= 0 && x < data->width
			&& sized_x >= 0 && sized_x < data->width
			&& sized_y >= 0 && sized_y < data->height)
		{
			_mlx_pixel_put(data, x, sized_y, LINE_COLOR);
			_mlx_pixel_put(data, sized_x, y, LINE_COLOR);
		}
		size--;
	}
	return (1);
}

static void	calc_step(t_vector delta, t_vector direction,
		t_vector *current, int *act)
{
	act[1] = act[0] * 2;
	if (act[1] >= -delta.y)
	{
		act[0] -= delta.y;
		current->x += direction.x;
	}
	if (act[1] <= delta.x)
	{
		act[0] += delta.x;
		current->y += direction.y;
	}
}

int	optimize_pos(t_vector *start, t_vector *end, t_data data)
{
	if (start->x >= 0 && start->x < data.width
		&& start->y >= 0 && start->y < data.height
		&& end->x >= 0 && end->x < data.width
		&& end->y >= 0 && end->y < data.height)
		return (1);
	if ((optimize_point_x(start, end, data)
			& optimize_point_y(start, end, data))
		&& (optimize_point_x(end, start, data)
			& optimize_point_y(end, start, data)))
		return (1);
	return (0);
}

void	draw_line(t_vector start, t_vector end, t_data *data)
{
	t_vector	delta;
	t_vector	direction;
	t_vector	current;
	int			act[2];

	if (!optimize_pos(&start, &end, *data))
		return ;
	delta.x = abs((int)end.x - (int)start.x);
	delta.y = abs((int)end.y - (int)start.y);
	direction = vector_create(1, 1, 0);
	if (end.x < start.x)
		direction.x *= -1;
	if (end.y < start.y)
		direction.y *= -1;
	current.x = (int)start.x;
	current.y = (int)start.y;
	act[0] = delta.x - delta.y;
	while ((int)current.x != (int)end.x
		|| (int)current.y != (int)end.y)
	{
		draw_point(current.x, current.y, data);
		calc_step(delta, direction, &current, act);
	}
}
