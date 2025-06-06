/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:24:32 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 15:34:00 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* pixel_put :
	change the color of the pixel to the given color
	starting at the beginning of the image, we have to point to the
	relevant pixel, then we change its color, coded in an int (0xTTRRGGBB)
*/
void	pixel_put(t_fractol *f, int x, int y, int color)
{
	int	*pixel;

	pixel = f->addr + x + y * WIDTH;
	*pixel = color;
}

/* set_image :
	create the img and set the address of the first pixel
	reset the image if there was one already
*/
void	set_image(t_fractol *f)
{
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		end_fractol(f, "Error creating mlx image, program end", 0);
	f->addr = (int *) mlx_get_data_addr(f->img, &bits_per_pixel,
			&line_length, &endian);
}

/* calculate_fractal :
	call the relevant function, depending on the fractal type
*/
unsigned int	calculate_fractal(t_fractol *f, double cr, double ci)
{
	if (f->f_type == MANDELBROT)
		return (mandelbrot(f, cr, ci));
	else if (f->f_type == JULIA)
		return (julia(f, cr, ci));
	else if (f->f_type == BURNING_SHIP)
		return (burning_ship(f, cr, ci));
	else if (f->f_type == PHOENIX)
		return (phoenix(f, cr, ci));
	else if (f->f_type == MANOWAR)
		return (manowar(f, cr, ci));
	return (0);
}

/* render :
	calculate and set the color pixel by pixel and display the image
*/
void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		n_iter_p;

	set_image(f);
	set_color(f);
	mlx_clear_window(f->mlx, f->win);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			cr = f->center_r + ((double) x - WIDTH / 2) / WIDTH * f->frame_r;
			ci = f->center_i + + ((double) y - HEIGHT / 2) / HEIGHT
				* f->frame_i;
			n_iter_p = calculate_fractal(f, cr, ci);
			pixel_put(f, x, y, f->palette[n_iter_p]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
