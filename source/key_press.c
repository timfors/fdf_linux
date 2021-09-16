/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:39:03 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/02 13:09:17 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_set(int keycode, t_controls *controls)
{
	if (keycode == KEY_ROTATE_X)
		controls->rot.x = 1;
	else if (keycode == KEY_R_ROTATE_X)
		controls->rot.x = -1;
	else if (keycode == KEY_ROTATE_Y)
		controls->rot.y = 1;
	else if (keycode == KEY_R_ROTATE_Y)
		controls->rot.y = -1;
	else if (keycode == KEY_ROTATE_Z)
		controls->rot.z = 1;
	else if (keycode == KEY_R_ROTATE_Z)
		controls->rot.z = -1;
}

void	translate_set(int keycode, t_controls *controls)
{
	if (keycode == KEY_MOVE_X)
		controls->move.x = 1;
	else if (keycode == KEY_R_MOVE_X)
		controls->move.x = -1;
	else if (keycode == KEY_MOVE_Y)
		controls->move.y = 1;
	else if (keycode == KEY_R_MOVE_Y)
		controls->move.y = -1;
	else if (keycode == KEY_MOVE_Z)
		controls->move.z = 1;
	else if (keycode == KEY_R_MOVE_Z)
		controls->move.z = -1;
}

void	scale_set(int keycode, t_controls *controls)
{
	if (keycode == KEY_ZOOM)
	{
		controls->scale.x = 1;
		controls->scale.y = 1;
		controls->scale.z = 1;
	}
	else if (keycode == KEY_R_ZOOM)
	{
		controls->scale.x = -1;
		controls->scale.y = -1;
		controls->scale.z = -1;
	}
}

void	switch_mode(t_data *data)
{
	if (data->view_mode == ISO_MODE)
		data->view_mode = PARAL_MODE;
	else
		data->view_mode = ISO_MODE;
}

int	key_pressed(int keycode, t_vars *vars)
{
	if (keycode == KEY_MOVE_X || keycode == KEY_R_MOVE_X
		|| keycode == KEY_MOVE_Y || keycode == KEY_R_MOVE_Y
		|| keycode == KEY_MOVE_Z || keycode == KEY_R_MOVE_Z)
		translate_set(keycode, vars->controls);
	else if (keycode == KEY_ROTATE_X || keycode == KEY_R_ROTATE_X
		|| keycode == KEY_ROTATE_Y || keycode == KEY_R_ROTATE_Y
		|| keycode == KEY_ROTATE_Z || keycode == KEY_R_ROTATE_Z)
		rotate_set(keycode, vars->controls);
	else if (keycode == KEY_ZOOM || keycode == KEY_R_ZOOM)
		scale_set(keycode, vars->controls);
	else if (keycode == KEY_EXIT)
		close_prog(vars);
	else if (keycode == KEY_SWITCH_MODE)
		switch_mode(vars->data);
	return (0);
}
