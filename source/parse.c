/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:40:20 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/07 17:29:02 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_splitted(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static void	check_pos(t_vector *max, t_vector *min, t_vector point)
{
	if (point.x > max->x)
		max->x = point.x;
	if (point.y > max->y)
		max->y = point.y;
	if (point.z > max->z)
		max->z = point.z;
	if (point.x < min->x)
		min->x = point.x;
	if (point.y < min->y)
		min->y = point.y;
	if (point.z < min->z)
		min->z = point.z;
}

void	set_to_center(t_object *object)
{
	t_vector	max_vals;
	t_vector	min_vals;
	t_list		*tmp;

	max_vals = vector_create(MIN_INT, MIN_INT, MIN_INT);
	min_vals = vector_create(MAX_INT, MAX_INT, MAX_INT);
	tmp = object->points;
	while (tmp)
	{
		check_pos(&max_vals, &min_vals, to_point(tmp)->pos);
		tmp = tmp->next;
	}
	tmp = object->points;
	while (tmp)
	{
		to_point(tmp)->pos.x -= (max_vals.x + min_vals.x) / 2 - object->pos.x;
		to_point(tmp)->pos.y -= (max_vals.y + min_vals.y) / 2 - object->pos.y;
		to_point(tmp)->pos.z -= (max_vals.z + min_vals.z) / 2 - object->pos.z;
		tmp = tmp->next;
	}
}

static int	parse_splitted(t_object *object, char **params, int line)
{
	int			num;
	int			col;
	t_list		*lst;
	t_vector	point_pos;
	t_point		*point;

	col = 0;
	while (params[col])
	{
		num = ft_atoi(params[col]);
		point_pos = vector_create(col, -num, -line);
		point = point_create(point_pos, col, line);
		if (!point)
			print_err("No memory!\n");
		point_connect(*object, point);
		lst = ft_lstnew(point);
		if (!lst)
			print_err("No memory!\n");
		ft_lstadd_front(&object->points, lst);
		col++;
	}
	return (1);
}

t_object	*parse(int fd)
{
	t_object	*res;
	int			line;
	char		**splitted;
	char		*str;
	int			read_code;

	if (fd <= 0)
		return (0);
	line = 0;
	read_code = get_next_line(fd, &str);
	if (read_code < 0)
		print_err("Read Error!\n");
	res = object_create(0);
	while (read_code > 0)
	{
		splitted = ft_split(str, ' ');
		if (!splitted || !parse_splitted(res, splitted, line++))
			print_err("No memory!\n");
		free_splitted(splitted);
		free(str);
		read_code = get_next_line(fd, &str);
	}
	if (str)
		free(str);
	return (res);
}
