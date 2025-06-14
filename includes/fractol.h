/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:58:13 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 16:14:13 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

/*		windows params	*/
# define HEIGHT 900
# define WIDTH 900

/*		computation params	*/
# define MIN_ITER 60
# define STEP_ITER 30
# define MAX_ITER 1800

/*		fractal possible types	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define PHOENIX 4
# define MANOWAR 5

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
	center_r/i : coordinates real/imaginary of the center of the screen
	frame_r/i : length of the real/imaginary axe
	zoom : zoom expressed in power of 2, only used for display
	julia_r\i : complex number c used for the julia set
	color : main color used to define the palette of color with the function
	psych_color : boolean to switch the color palette to psych_color mode
	palette : array of the color palette used
	iter : number of iteration used for computation
*/
typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	char		f_type;
	double		center_r;
	double		center_i;
	double		frame_r;
	double		frame_i;
	int			zoom;
	double		julia_r;
	double		julia_i;
	int			color;
	bool		psych_color;
	int			*palette;
	int			iter;
}	t_fractol;

/* complex:
	structure introduced later on in the projet to represent a complex number.
	most of the code was written without using it, it was introduced only
	to hande the norminette for the phoenix and manowar fractal set
*/
typedef struct s_complex
{
	double		r;
	double		i;
}	t_complex;

/*		fractol	*/

int				end_fractol(t_fractol *f, char *msg, char display_help);

/*		init	*/

void			c_init(t_fractol *f);
void			init(t_fractol *f);

/*		hook	*/

int				x_hook(t_fractol *f);
void			move(t_fractol *f, double distance, char direction, char msg);
void			zoom(t_fractol *f, double distance);
int				key_hook(int keycode, t_fractol *f);
int				mouse_hook(int keycode, int x, int y, t_fractol *f);

/*		color	*/

void			color_switch(t_fractol *f, size_t color, int incr);
void			set_color(t_fractol *f);

/*		fractal sets	*/

unsigned int	mandelbrot(t_fractol *f, double cr, double ci);
unsigned int	julia(t_fractol *f, double cr, double ci);
unsigned int	burning_ship(t_fractol *f, double cr, double ci);
unsigned int	phoenix(t_fractol *f, double cr, double ci);
unsigned int	manowar(t_fractol *f, double cr, double ci);

/*		render	*/

void			render(t_fractol *f);

/*		parser	*/

void			get_inputs(t_fractol *f, int argc, char **argv);
void			get_color(t_fractol *f, int argc, char **argv);

/*		messages	*/

void			print_header(void);
void			print_help(void);
void			print_command(void);
void			print_julia(t_fractol *f);
void			print_zoom(t_fractol *f, double distance);
void			print_progend(void);
void			print_move(t_fractol *f, char direction);
void			print_pmode(t_fractol *f);
void			print_cswitch(t_fractol *f, size_t color, int incr);
void			print_fchange(t_fractol *f);

#endif