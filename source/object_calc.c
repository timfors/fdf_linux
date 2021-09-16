/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 20:35:12 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/08 19:51:04 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_scale(t_object object, t_point *point)
{
	point->pos.x = point->pos.x * object.scale.x;
	point->pos.y = point->pos.y * object.scale.y;
	point->pos.z = point->pos.z * object.scale.z;
}

void	apply_pos(t_object object, t_point *point)
{
	point->pos.x += object.pos.x;
	point->pos.y += object.pos.y;
	point->pos.z += object.pos.z;
}

void	apply_rotation(t_object object, t_point *point)
{
	t_vector	start;

	start = point->pos;
	point->pos.x = point->pos.x;
	point->pos.y = start.y * cos(radian(object.rot.x))
		+ start.z * sin(radian(object.rot.x));
	point->pos.z = start.z * cos(radian(object.rot.x))
		- start.y * sin(radian(object.rot.x));
	start = point->pos;
	point->pos.x = start.x * cos(radian(object.rot.y))
		+ start.z * sin(radian(object.rot.y));
	point->pos.y = start.y;
	point->pos.z = start.z * cos(radian(object.rot.y))
		- start.x * sin(radian(object.rot.y));
	start = point->pos;
	point->pos.x = start.x * cos(radian(object.rot.z))
		- start.y * sin(radian(object.rot.z));
	point->pos.y = start.y * cos(radian(object.rot.z))
		+ start.x * sin(radian(object.rot.z));
	point->pos.z = start.z;
}

void	object_calc_point(t_object *object, t_point *point, int is_iso)
{
	point->pos = point->local_pos;
	if (is_iso)
		apply_iso(point);
	apply_rotation(*object, point);
	apply_scale(*object, point);
	apply_pos(*object, point);
}

void	object_calc_points_pos(t_object *object, int is_iso)
{
	t_point	*point;
	t_list	*tmp;

	tmp = object->points;
	while (tmp)
	{
		point = to_point(tmp);
		object_calc_point(object, point, is_iso);
		tmp = tmp->next;
	}
	set_to_center(object);
}
