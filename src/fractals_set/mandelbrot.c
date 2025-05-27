/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:04:49 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/27 11:23:16 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* mandelbrot :
	cf definition of Mandelbrot set : we test the convergence of the suite
	Since if |z| > 2 we obviously end up diverging, we note the number of 
	iterations to eventually reach this situation, while being limited to 
	N_ITER for computation time
*/
unsigned int	mandelbrot(int cr, int ci)
{
	unsigned int	k;
	int				zr;
	int				zi;

	k = -1;
	zr = 0;
	zi = 0;
	while (++k < N_ITER)
	{
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		if (zr * zr + zi * zi > 4)
			return (k);
	}
	return (k);
}
