/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:34:48 by julcleme          #+#    #+#             */
/*   Updated: 2025/11/25 09:13:13 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	img_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	polynomial_color_palette(double d)
{
	int	r;
	int	g;
	int	b;

	if (d < 0)
		d = 0;
	if (d > 1)
		d = 1;
	if (d >= 1.0)
		return (0x000000);
	r = (int)(9 * (1 - d) * d * d * d * 255);
	g = (int)(15 * (1 - d) * (1 - d) * d * d * 255);
	b = (int)(8.5 * (1 - d) * (1 - d) * (1 - d) * d * 255);
	return ((r << 16) | (g << 8) | b);
}

int	gray_color_palette(double d)
{
	int	r;
	int	g;
	int	b;

	if (d < 0)
		d = 0;
	if (d > 1)
		d = 1;
	if (d >= 1.0)
		return (0x000000);
	r = (int)(d * 255);
	g = (int)(d * 255);
	b = (int)(d * 255);
	return ((r << 16) | (g << 8) | b);
}

int	lerp_color(double d)
{
	int	r;
	int	g;
	int	b;

	if (d < 0)
		d = 0;
	if (d > 1)
		d = 1;
	r = (int)(d * 255.0);
	g = 0;
	b = (int)((1.0 - d) * 255.0);
	return ((r << 16) | (g << 8) | b);
}
