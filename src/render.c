/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:24:32 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/27 12:00:25 by ljudd            ###   ########.fr       */
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
*/
void	set_image(t_fractol *f)
{
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	f->img = mlx_new_img(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &bits_per_pixel, &line_length, &endian);
}

/* calculate_fractal :
	call the relevant function, depending on the fractal type
*/
unsigned int	calculate_fractal(t_fractol *f, int cr, int ci)
{
	if (f->f_type == MANDELBROT)
		return (mandelbrot(cr, ci));
	return (0);
}

/* render :
	calculate and set the color pixel by pixel and display the image
*/
void	render(t_fractol *f)
{
	int	x;
	int	y;
	int	cr;
	int	ci;
	int	n_iter_p;

	set_image(f);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			cr = f->min_r + x * (f->max_r - f->min_r) / (WIDTH - 1);
			ci = f->min_i + y * (f->max_i - f->min_i) / (HEIGHT - 1);
			n_iter_p = calculate_fractal(f, cr, ci);
			pixel_put(f, x, y, f->palette[n_iter_p]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
