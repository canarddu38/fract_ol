/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:25:33 by julcleme          #+#    #+#             */
/*   Updated: 2025/11/25 09:49:50 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define MAX_ITER 1000
# define SCROLL_SPEED 0.1
# define MOVE_SPEED	1

# define KEY_ESC 65307
# define KEY_RIGHT_ARROW 65363
# define KEY_DOWN_ARROW 65364
# define KEY_LEFT_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_ZOOM_IN 4
# define KEY_ZOOM_OUT 5

# define TYPE_UNKNOWN 0
# define TYPE_MANDELBROT 1
# define TYPE_JULIA 2
# define TYPE_BURNING_SHIP 3

# define SCREEN_WIDTH 1900
# define SCREEN_HEIGHT 1500

typedef struct s_img_data
{
	int		type;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	void	*mlx;
	void	*win;
	void	*img;
	int		endian;
	void	*addr;
	int		bpp;
	int		line_len;
	double	c_r;
	double	c_i;
	int		(*color_palette)(double);
}	t_img_data;

void	img_pixel_put(t_img_data *img, int x, int y, int color);
int		gray_color_palette(double t);
int		polynomial_color_palette(double t);
int		lerp_color(double d);

double	julia(double a, double b, double c_r, double c_i);
void	draw_julia(t_img_data *img);

double	burning_ship(double a, double b);

int		get_type(char *arg);
void	get_fractal(int num, t_img_data *img);

#endif