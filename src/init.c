/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:31:10 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/27 11:45:17 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* c_init :
	clean initialisation of f with default values for :
	- easier debugging
	- avoiding warning while calling functions on non initialized parameters
*/
void	c_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->addr = NULL;
	f->f_type = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->palette = NULL;
}

/* set_layout :
	initial layout is dependent of the fractal type we display
	to get something aesthetic
*/
void	set_layout(t_fractol *f)
{
	if (!f->mlx)
		return ;
	if (f->f_type == MANDELBROT)
	{
		f->min_r = -2;
		f->max_r = 1;
		f->min_i = -1;
		f->max_i = 1;
	}
}

/* init :
	initializes mlx, win and the color palette
*/
void	init(t_fractol *f)
{
	f->mlx = mlx_init;
	if (!f->mlx)
		end_fractol(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		end_fractol(f);
	f->f_type = MANDELBROT;
	set_layout(f);
	set_color(f);
	if (!f->palette)
		end_fractol(f);
}
