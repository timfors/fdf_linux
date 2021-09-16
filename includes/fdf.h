/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:19:07 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/09 13:51:46 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define S_WIDTH 960
# define S_HEIGHT 870
# define LINE_SIZE 1
# define LINE_COLOR 0x00ffffff
# define COLOR_BACKGROUND 0x00000000
# define ROT_SPEED 0.2
# define MOVE_SPEED 0.5
# define SCALE_SPEED 1.01f
# define ISO_MODE 0
# define PARAL_MODE 1

# include <mlx_int.h>
# include <libft.h>
# include <mlx.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <get_next_line.h>
# include "key_codes.h"

void			print_points(t_list *lst);

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vector;

t_vector		vector_create(int x, int y, int z);

typedef struct s_point
{
	t_vector	pos;
	t_vector	local_pos;
	t_list		*connected;
	int			line;
	int			col;
}				t_point;

typedef struct s_object
{
	t_vector	pos;
	t_vector	rot;
	t_vector	scale;
	t_list		*points;
}			t_object;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		width;
	int		height;
	int		line_length;
	int		endian;
	int		view_mode;
}			t_data;

typedef struct s_controls
{
	t_vector	move;
	t_vector	rot;
	t_vector	scale;
}				t_controls;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_window;
	t_data		*data;
	t_controls	*controls;
	t_object	*object;
}				t_vars;

t_data			*data_create(void *mlx, int width, int height);
void			data_clear(t_data **data);

void			fill_image(t_data *data, int color);
void			draw_line(t_vector start, t_vector end, t_data *data);

t_object		*object_create(t_list *points);
t_list			*object_get(t_object object, int col, int line);
void			object_calc_points_pos(t_object *object, int is_iso);
void			object_calc_point(t_object *object, t_point *point, int is_iso);
void			object_draw(t_object object, t_data *data);
void			object_translate(t_object *object, t_vector delta);
void			object_delete(t_object *obj);

void			set_to_center(t_object *object);

void			apply_pos(t_object object, t_point *point);
void			apply_rot(t_object object, t_point *point);
void			apply_scale(t_object object, t_point *point);
void			apply_iso(t_point *point);

void			_mlx_pixel_put(t_data *data, int x, int y, int color);

t_point			*point_create(t_vector local_pos, int line, int col);
void			point_connect(t_object object, t_point *point);
t_point			*to_point(t_list *lst);

int				key_pressed(int keycode, t_vars *vars);
int				key_released(int keycode, t_vars *vars);
int				close_prog(t_vars *vars);
int				render_next_frame(t_vars *vars);

t_vector		vector_to_screen(t_vector pos);
double			radian(double angle);

int				get_y(int x, t_vector start, t_vector end);
int				get_x(int y, t_vector start, t_vector end);
int				optimize_point_x(t_vector *start, t_vector *end, t_data data);
int				optimize_point_y(t_vector *start, t_vector *end, t_data data);

void			print_err(char *str);

t_object		*parse(int fd);
#endif
