/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:10:31 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/08 18:58:22 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_image(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
			_mlx_pixel_put(data, j++, i, color);
		i++;
	}
}

t_data	*data_create(void *mlx, int width, int height)
{
	t_data	*img;

	img = ft_calloc(sizeof(t_data), 1);
	if (!img)
		print_err("No memory!\n");
	img->img = mlx_new_image(mlx, width, height);
	if (!img->img)
		print_err("No memory!\n");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = width;
	img->height = height;
	fill_image(img, COLOR_BACKGROUND);
	ft_putstr_fd("IMAGE INITED!\n", 1);
	return (img);
}

void	print_err(char *str)
{
	if (errno == 0)
		ft_putstr_fd(str, 1);
	else
		perror(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	errno = 0;
	if (argc != 2)
		print_err("Usage: ./fdf [FILE]\n");
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		print_err("File open error!\n");
	vars.object = parse(fd);
	close(fd);
	vars.controls = ft_calloc(sizeof(t_controls), 1);
	if (!vars.controls)
		print_err("No memory!\n");
	vars.mlx = mlx_init();
	vars.data = data_create(vars.mlx, S_WIDTH, S_HEIGHT);
	vars.mlx_window = mlx_new_window(vars.mlx, S_WIDTH, S_HEIGHT, "FDF");
	mlx_hook(vars.mlx_window, KeyPress, 255, key_pressed, &vars);
	mlx_hook(vars.mlx_window, KeyRelease, 255, key_released, &vars);
	mlx_hook(vars.mlx_window, 17, 0, close_prog, &vars);
	object_calc_points_pos(vars.object, vars.data->view_mode == ISO_MODE);
	object_draw(*vars.object, vars.data);
	mlx_put_image_to_window(vars.mlx, vars.mlx_window, vars.data->img, 0, 0);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}
