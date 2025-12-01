/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:04:03 by julcleme          #+#    #+#             */
/*   Updated: 2025/11/25 09:14:57 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_window(void *mlx)
{
	(void)mlx;
	exit(0);
	return (0);
}

int	handle_key(int key, t_img_data *img)
{
	double	delta;
	int		direction[2];

	delta = MOVE_SPEED * (img->x_max - img->x_min) / 8;
	direction[0] = 0;
	direction[1] = 0;
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_LEFT_ARROW)
		direction[0] = -1;
	else if (key == KEY_RIGHT_ARROW)
		direction[0] = 1;
	else if (key == KEY_UP_ARROW)
		direction[1] = 1;
	else if (key == KEY_DOWN_ARROW)
		direction[1] = -1;
	else
		return (0);
	img->x_min += delta * direction[0];
	img->x_max += delta * direction[0];
	img->y_min += delta * direction[1];
	img->y_max += delta * direction[1];
	draw_julia(img);
	return (0);
}

int	mouse_event(int button, int x, int y, t_img_data *img)
{
	double	mouse_r;
	double	mouse_i;
	double	zoom_factor;

	zoom_factor = 1 + SCROLL_SPEED;
	mouse_r = img->x_min + x * (img->x_max - img->x_min) / SCREEN_WIDTH;
	mouse_i = img->y_max - y * (img->y_max - img->y_min) / SCREEN_HEIGHT;
	if (button == KEY_ZOOM_IN)
	{
		img->x_min = mouse_r + (img->x_min - mouse_r) * zoom_factor;
		img->x_max = mouse_r + (img->x_max - mouse_r) * zoom_factor;
		img->y_min = mouse_i + (img->y_min - mouse_i) * zoom_factor;
		img->y_max = mouse_i + (img->y_max - mouse_i) * zoom_factor;
	}
	if (button == KEY_ZOOM_OUT)
	{
		img->x_min = mouse_r + (img->x_min - mouse_r) / zoom_factor;
		img->x_max = mouse_r + (img->x_max - mouse_r) / zoom_factor;
		img->y_min = mouse_i + (img->y_min - mouse_i) / zoom_factor;
		img->y_max = mouse_i + (img->y_max - mouse_i) / zoom_factor;
	}
	draw_julia(img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_img_data	img;

	if (argc != 3)
		return (1);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "fract_ol");
	img.img = mlx_new_image(img.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	mlx_key_hook(img.win, handle_key, &img);
	mlx_hook(img.win, 17, 0, close_window, img.mlx);
	img.x_min = -2.5;
	img.x_max = 1.0;
	img.y_min = -1.0;
	img.y_max = 1.0;
	img.type = get_type(argv[1]);
	if (img.type == TYPE_UNKNOWN)
		return (1);
	get_fractal(ft_atoi(argv[2]), &img);
	img.color_palette = polynomial_color_palette;
	mlx_mouse_hook(img.win, mouse_event, &img);
	draw_julia(&img);
	mlx_loop(img.mlx);
	return (0);
}
