#include "../includes/fdf.h"

void	object_free(t_object *object)
{
	t_list	*tmp;
	t_list	*next;
	t_list	*connected;

	tmp = object->points;
	while (tmp)
	{
		connected = to_point(tmp)->connected;
		while (connected)
		{
			next = connected->next;
			free(connected);
			connected = next;
		}
		free(to_point(tmp));
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(object);
}

int	close_prog(t_vars *vars)
{
	if (vars->controls)
		free(vars->controls);
	mlx_destroy_window(vars->mlx, vars->mlx_window);
	if (vars->object)
		object_free(vars->object);
	mlx_destroy_image(vars->mlx, vars->data->img);
	if (vars->data)
		free(vars->data);
	exit(0);
	return (0);
}
