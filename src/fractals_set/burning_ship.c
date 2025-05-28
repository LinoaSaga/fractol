/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:04:49 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/28 15:56:53 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* abs_value :
	return the abs value of a
*/
static double	abs_value(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

/* burning_ship :
	similar to Mandelbrot, the absolute value of the imaginary part and 
	real part are used instead during each iteration
*/
unsigned int	burning_ship(double cr, double ci)
{
	unsigned int	k;
	double			zr;
	double			zi;
	double			tmp;

	k = -1;
	zr = 0;
	zi = 0;
	while (++k < MAX_ITER)
	{
		if (zr * zr + zi * zi > 4)
			return (k);
		zr = abs_value(zr);
		zi = abs_value(zi);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	return (k);
}
