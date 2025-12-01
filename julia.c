/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:34:48 by julcleme          #+#    #+#             */
/*   Updated: 2025/11/25 08:43:55 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	julia(double init_x, double init_y, double c_r, double c_i)
{
	double	zx;
	double	zy;
	double	z2[2];
	double	tmp;
	size_t	iter;

	zx = init_x;
	zy = init_y;
	z2[0] = zx * zx;
	z2[1] = zy * zy;
	iter = 0;
	while (z2[0] + z2[1] <= 4.0 && iter < MAX_ITER)
	{
		tmp = z2[0] - z2[1] + c_r;
		zy = 2 * zx * zy + c_i;
		zx = tmp;
		z2[0] = zx * zx;
		z2[1] = zy * zy;
		iter++;
	}
	if (iter == MAX_ITER)
		return (MAX_ITER);
	return (iter + 1.0 - log(log(sqrt(z2[0] + z2[1]))) / log(2.0));
}

void	draw_julia(t_img_data *img)
{
	int		y;
	int		x;
	double	a;
	double	b;
	double	mu;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		b = img->y_max - y * (img->y_max - img->y_min) / SCREEN_HEIGHT;
		while (++x < SCREEN_WIDTH)
		{
			a = img->x_min + x * (img->x_max - img->x_min) / SCREEN_WIDTH;
			if (img->type == TYPE_MANDELBROT)
				mu = julia(0, 0, a, b);
			else if (img->type == TYPE_BURNING_SHIP)
				mu = burning_ship(a, b);
			else
				mu = julia(a, b, img->c_r, img->c_i);
			img_pixel_put(img, x, y, (img->color_palette)(mu / MAX_ITER));
		}
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
