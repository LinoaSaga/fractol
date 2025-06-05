/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:54:54 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/05 18:13:09 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_switch(t_fractol *f, size_t color, int incr)
{
	int	rgb[3];

	rgb[0] = (f->color) & 0xff;
	rgb[1] = (f->color >> 8) & 0xff;
	rgb[2] = (f->color >> 16) & 0xff;
	rgb[color] = (rgb[color] + incr * 10) % 256;
	if (rgb[color] < 0)
		rgb[color] += 256;
	f->color = (rgb[2] << 16 | rgb[1] << 8 | rgb[0]);
	print_cswitch(f, color, incr);
}

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
	color2 = f->color;
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

/* psych_color :
	Change the palette obtain with the neon function to obtain a psychedelic
	effect : concretely, we reverse one color on two
*/
void	psych_color(t_fractol *f)
{
	size_t	k;
	int		rgb[3];

	k = -1;
	while (++k < MAX_ITER)
	{
		if (k % 2)
		{
			rgb[0] = (f->palette[k]) & 0xff;
			rgb[1] = (f->palette[k] >> 8) & 0xff;
			rgb[2] = (f->palette[k] >> 16) & 0xff;
			rgb[0] = (255 - rgb[0]);
			rgb[1] = (255 - rgb[1]);
			rgb[2] = (255 - rgb[2]);
			f->palette[k] = 0xff << 24 | rgb[2] << 16
				| rgb[1] << 8 | rgb[0];
		}
	}
}

/* set_color :
	malloc the color palette, returning NULL in case of error
	color is fixed with a unique sub function for now
*/
void	set_color(t_fractol *f)
{
	if (!f->mlx)
		return ;
	if (!f->palette)
		f->palette = malloc((MAX_ITER + 1) * sizeof(int));
	if (!f->palette)
		end_fractol(f, "Error allocating color palette, program end", 0);
	set_color_neon(f);
	if (f->psych_color)
		psych_color(f);
}
