/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_db.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:52:29 by julcleme          #+#    #+#             */
/*   Updated: 2025/11/25 09:12:04 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	get_type(char *arg)
{
	if (ft_strlen(arg) != 1)
		exit(1);
	if (arg[0] == 'm' || arg[0] == 'M')
		return (TYPE_MANDELBROT);
	if (arg[0] == 'j' || arg[0] == 'J')
		return (TYPE_JULIA);
	if (arg[0] == 'b' || arg[0] == 'B')
		return (TYPE_BURNING_SHIP);
	return (TYPE_UNKNOWN);
}

void	get_fractal(int num, t_img_data *img)
{
	if (img->type == TYPE_JULIA)
	{
		if (num == 0)
		{
			img->c_r = -0.5125;
			img->c_i = 0.5213;
		}
		else if (num == 1)
		{
			img->c_r = -0.7;
			img->c_i = 0.27015;
		}
		else if (num == 2)
		{
			img->c_r = 0.3;
			img->c_i = 0.5;
		}
		else if (num == 3)
		{
			img->c_r = 0.0;
			img->c_i = -0.8;
		}
	}
}
