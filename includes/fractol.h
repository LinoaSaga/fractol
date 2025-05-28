/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:58:13 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/28 15:58:50 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "keys.h"
# include <stdlib.h>
# include <stdio.h>

/*		windows params	*/
# define HEIGHT 900
# define WIDTH 900

/*		computation params	*/
# define MAX_ITER 60

/*		fractal possible types	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

/*		colors	*/
# define COLOR_BLACK 0x000000
# define COLOR_EMERALD_SEA 0x00e1d0
# define COLOR_WHITE 0xffffff

/*  t_fractol:
	core data structure of the program
	mlx = pointer to the location of the used mlx instance
	win = pointer to the mlx window printed
	img = pointer to the img we put in the window
	addr = address of the img to manipulate pixel
	f_type = type of fractol to be printed
	min\max_r\i : minimum\maximum real\imaginary number of the graph
	palette : array of the color palette used
*/
typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	char		f_type;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		julia_r;
	double		julia_i;
	int			*palette;
}	t_fractol;

/*		init	*/

void			c_init(t_fractol *f);
void			init(t_fractol *f);

/*		hook	*/

int				end_fractol(t_fractol *f);
int				key_hook(int keycode, t_fractol *f);
int				mouse_hook(int keycode, int x, int y, t_fractol *f);

/*		color	*/

void			set_color(t_fractol *f);

/*		fractal sets	*/

unsigned int	mandelbrot(double cr, double ci);
unsigned int	julia(t_fractol *f, double cr, double ci);
unsigned int	burning_ship(double cr, double ci);

/*		render	*/

void			render(t_fractol *f);

#endif