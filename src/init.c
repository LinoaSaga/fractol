/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:31:10 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 16:11:24 by ljudd            ###   ########.fr       */
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
	f->center_r = 0.0;
	f->center_i = 0.0;
	f->frame_r = 0.0;
	f->frame_i = 0.0;
	f->zoom = 0;
	f->julia_r = 0.0;
	f->julia_i = 0.0;
	f->color = 0x000000;
	f->psych_color = false;
	f->palette = NULL;
	f->iter = 0;
}

/* set_layout :
	initial layout is dependent of the fractal type we display
	to get something aesthetic
	calculate the frame_i with frame_r to avoid image deformation
*/
void	set_layout(t_fractol *f)
{
	if (!f->mlx)
		return ;
	if (f->f_type == MANDELBROT)
	{
		f->center_r = -0.5;
		f->center_i = 0.0;
		f->frame_r = 3.0;
		f->frame_i = f->frame_r * HEIGHT / WIDTH;
	}
	else
	{
		f->center_r = 0.0;
		f->center_i = 0.0;
		f->frame_r = 4.0;
		f->frame_i = f->frame_r * HEIGHT / WIDTH;
	}
	f->zoom = 0;
	f->iter = MIN_ITER;
}

/* init :
	initializes mlx, win and the color palette
*/
void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		end_fractol(f, "Error initializing mlx, program end", 0);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		end_fractol(f, "Error mlx window creation, program end", 0);
	set_layout(f);
}
