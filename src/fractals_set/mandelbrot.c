/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:04:49 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 15:36:56 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* mandelbrot :
	cf definition of Mandelbrot set : we test the convergence of the suite
	Since if |z| > 2 we end up diverging, we note the number of 
	iterations to eventually reach this situation, while being limited to 
	MAX_ITER for computation time
*/
unsigned int	mandelbrot(t_fractol *f, double cr, double ci)
{
	int	k;
	double			zr;
	double			zi;
	double			tmp;

	k = -1;
	zr = 0;
	zi = 0;
	while (++k < f->iter)
	{
		if (zr * zr + zi * zi > 4)
			return (k);
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	return (k);
}
