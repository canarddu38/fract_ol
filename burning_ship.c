/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcleme <julcleme@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:37:07 by julcleme          #+#    #+#             */
/*   Updated: 2025/11/25 08:37:50 by julcleme         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	burning_ship(double a, double b)
{
	double zx = 0.0;
	double zy = 0.0;
	double zx2 = 0.0;
	double zy2 = 0.0;
	size_t iter = 0;

	while (zx2 + zy2 <= 4.0 && iter < MAX_ITER)
	{
		double x = zx;
		double y = zy;

		zx = x * x - y * y + a;
		zy = 2 * fabs(x * y) + b;

		zx2 = zx * zx;
		zy2 = zy * zy;

		iter++;
	}
	return (iter);
}
