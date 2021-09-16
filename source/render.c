/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:22:57 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/09 13:57:35 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_move(t_controls controls, t_object *obj)
{
	if (controls.move.x || controls.move.y || controls.move.z)
	{
		obj->pos.x += controls.move.x * MOVE_SPEED;
		obj->pos.y += controls.move.y * MOVE_SPEED;
		obj->pos.z += controls.move.z * MOVE_SPEED;
		return (1);
	}
	return (0);
}

int	check_rotation(t_controls controls, t_object *obj)
{
	if (controls.rot.x || controls.rot.y || controls.rot.z)
	{
		obj->rot.x += controls.rot.x * ROT_SPEED;
		obj->rot.y += controls.rot.y * ROT_SPEED;
		obj->rot.z += controls.rot.z * ROT_SPEED;
		return (1);
	}
	return (0);
}

int	check_scale(t_controls controls, t_object *obj)
{
	if (controls.scale.x || controls.scale.y || controls.scale.z)
	{
		if (controls.scale.x > 0)
			obj->scale.x *= SCALE_SPEED;
		else
			obj->scale.x /= SCALE_SPEED;
		if (controls.scale.y > 0)
			obj->scale.y *= SCALE_SPEED;
		else
			obj->scale.y /= SCALE_SPEED;
		if (controls.scale.z > 0)
			obj->scale.z *= SCALE_SPEED;
		else
			obj->scale.z /= SCALE_SPEED;
		return (1);
	}
	return (0);
}

int	check_controls(t_controls controls, t_object *obj)
{
	if (check_rotation(controls, obj)
		| check_move(controls, obj)
		| check_scale(controls, obj))
		return (1);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	static int	view_mode = -1;

	if (check_controls(*vars->controls, vars->object)
		|| view_mode != vars->data->view_mode)
	{
		fill_image(vars->data, COLOR_BACKGROUND);
		object_calc_points_pos(vars->object, vars->data->view_mode == ISO_MODE);
		view_mode = vars->data->view_mode;
		object_draw(*vars->object, vars->data);
		mlx_put_image_to_window(vars->mlx, vars->mlx_window,
			vars->data->img, 0, 0);
	}
	return (1);
}
