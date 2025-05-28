/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:54:54 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/28 14:30:55 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ponderate means :
	calculate the ponderate mean of the two colors with weight w
*/
int	ponderate_mean(int color1, int color2, double w)
{
	int	rgb1[3];
	int	rgb2[3];
	int	rgb_res[3];

	rgb1[0] = (color1) & 0xff;
	rgb1[1] = (color1 >> 8) & 0xff;
	rgb1[2] = (color1 >> 16) & 0xff;
	rgb2[0] = (color2) & 0xff;
	rgb2[1] = (color2 >> 8) & 0xff;
	rgb2[2] = (color2 >> 16) & 0xff;
	rgb_res[0] = (1 - w) * rgb1[0] + w * rgb2[0];
	rgb_res[1] = (1 - w) * rgb1[1] + w * rgb2[1];
	rgb_res[2] = (1 - w) * rgb1[2] + w * rgb2[2];
	return (0xff << 24 | rgb_res[2] << 16 | rgb_res[1] << 8 | rgb_res[0]);
}

/* set_color_neon :
	calculate a linear interpolation for colors, from black (0)
	to emerald green (N / 2) to white (N)
	color is black in case of convergence
*/
void	set_color_neon(t_fractol *f)
{
	int		color1;
	int		color2;
	int		color3;
	double	w;
	int		k;

	color1 = COLOR_BLACK;
	color2 = COLOR_EMERALD_SEA;
	color3 = COLOR_WHITE;
	k = -1;
	while (++k < MAX_ITER / 2)
	{
		w = ((double) k) / (MAX_ITER / 2.0 - 1.0);
		f->palette[k] = ponderate_mean(color1, color2, w);
	}
	while (k < MAX_ITER)
	{
		w = ((double) k - MAX_ITER / 2.0) / (MAX_ITER - 1.0 - MAX_ITER / 2.0);
		f->palette[k] = ponderate_mean(color2, color3, w);
		k++;
	}
	f->palette[k] = 0xff000000;
}

/* set_color :
	malloc the color palette, returning NULL in case of error
	color is fixed with a unique sub function for now
*/
void	set_color(t_fractol *f)
{
	if (!f->mlx)
		return ;
	f->palette = malloc((MAX_ITER + 1) * sizeof(int));
	if (!f->palette)
		return ;
	set_color_neon(f);
}
