/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:34:25 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 15:36:51 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* phoenix :
	a variant of the julia set, with a different polynomial formula
*/
unsigned int	phoenix(t_fractol *f, double cr, double ci)
{
	int	k;
	t_complex		zn;
	t_complex		zn1;
	t_complex		tmp;

	k = -1;
	zn.r = cr;
	zn.i = ci;
	zn1.r = 0;
	zn1.i = 0;
	while (++k < f->iter)
	{
		if (zn.r * zn.r + zn.i * zn.i > 4)
			return (k);
		tmp.i = 2 * zn.r * zn.i - 0.5 * zn1.i + f->julia_i;
		tmp.r = zn.r;
		zn.r = zn.r * zn.r - zn.i * zn.i - 0.5 * zn1.r + f->julia_r;
		zn1.i = zn.i;
		zn.i = tmp.i;
		zn1.r = tmp.r;
	}
	return (k);
}
