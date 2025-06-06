/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:36:39 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 15:36:58 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* julia :
	similar to Mandelbrot, but intialization is done with the number
	and iteration is done with the julia parameter
*/
unsigned int	julia(t_fractol *f, double cr, double ci)
{
	int	k;
	double			zr;
	double			zi;
	double			tmp;

	k = -1;
	zr = cr;
	zi = ci;
	while (++k < f->iter)
	{
		if (zr * zr + zi * zi > 4)
			return (k);
		tmp = 2 * zr * zi + f->julia_i;
		zr = zr * zr - zi * zi + f->julia_r;
		zi = tmp;
	}
	return (k);
}
