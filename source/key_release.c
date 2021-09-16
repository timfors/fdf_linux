/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:39:50 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/02 13:09:34 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_unset(int keycode, t_controls *controls)
{
	if (keycode == KEY_ROTATE_X)
		controls->rot.x = 0;
	else if (keycode == KEY_R_ROTATE_X)
		controls->rot.x = 0;
	else if (keycode == KEY_ROTATE_Y)
		controls->rot.y = 0;
	else if (keycode == KEY_R_ROTATE_Y)
		controls->rot.y = 0;
	else if (keycode == KEY_ROTATE_Z)
		controls->rot.z = 0;
	else if (keycode == KEY_R_ROTATE_Z)
		controls->rot.z = 0;
}

void	translate_unset(int keycode, t_controls *controls)
{
	if (keycode == KEY_MOVE_X)
		controls->move.x = 0;
	else if (keycode == KEY_R_MOVE_X)
		controls->move.x = 0;
	else if (keycode == KEY_MOVE_Y)
		controls->move.y = 0;
	else if (keycode == KEY_R_MOVE_Y)
		controls->move.y = 0;
	else if (keycode == KEY_MOVE_Z)
		controls->move.z = 0;
	else if (keycode == KEY_R_MOVE_Z)
		controls->move.z = 0;
}

void	scale_unset(int keycode, t_controls *controls)
{
	if (keycode == KEY_ZOOM || keycode == KEY_R_ZOOM)
	{
		controls->scale.x = 0;
		controls->scale.y = 0;
		controls->scale.z = 0;
	}
}

int	key_released(int keycode, t_vars *vars)
{
	if (keycode == KEY_MOVE_X || keycode == KEY_R_MOVE_X
		|| keycode == KEY_MOVE_Y || keycode == KEY_R_MOVE_Y
		|| keycode == KEY_MOVE_Z || keycode == KEY_R_MOVE_Z)
		translate_unset(keycode, vars->controls);
	else if (keycode == KEY_ROTATE_X || keycode == KEY_R_ROTATE_X
		|| keycode == KEY_ROTATE_Y || keycode == KEY_R_ROTATE_Y
		|| keycode == KEY_ROTATE_Z || keycode == KEY_R_ROTATE_Z)
		rotate_unset(keycode, vars->controls);
	else if (keycode == KEY_ZOOM || keycode == KEY_R_ZOOM)
		scale_unset(keycode, vars->controls);
	return (0);
}
