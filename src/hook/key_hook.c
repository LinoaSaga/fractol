/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:13:51 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/02 19:41:46 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* zoom :
	zoom expressed in % of the range
*/
void	zoom(t_fractol *f, double distance)
{
	double	range_r;
	double	range_i;

	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	f->max_r = f->max_r + range_r * (distance - 1.0) / 2.0;
	f->min_r = f->max_r - distance * range_r;
	f->max_i = f->max_i + range_i * (distance - 1.0) / 2.0;
	f->min_i = f->max_i - distance * range_i;
}

/* key_hook_fractal :
	sub function to handle fractal type changes keyboard inputs
*/
void	key_hook_fractal(int keycode, t_fractol *f)
{
	if (keycode == KEY_1 | keycode == KEY_1_NUMPAD)
		f->f_type = MANDELBROT;
	else if (keycode == KEY_2 | keycode == KEY_2_NUMPAD)
		f->f_type = JULIA;
	else if (keycode == KEY_3 | keycode == KEY_3_NUMPAD)
		f->f_type = BURNING_SHIP;
	else if (keycode == KEY_4 | keycode == KEY_4_NUMPAD)
		f->f_type = PHOENIX;
	else if (keycode == KEY_5 | keycode == KEY_5_NUMPAD)
		f->f_type = MANOWAR;
}

/* key_hook_color :
	sub function to handle the color change inputs with the keyboard
*/
void	key_hook_color(int keycode, t_fractol *f)
{
	if (keycode == KEY_R)
		color_switch(f, 2, 1);
	else if (keycode == KEY_G)
		color_switch(f, 1, 1);
	else if (keycode == KEY_B)
		color_switch(f, 0, 1);
	else if (keycode == KEY_E)
		color_switch(f, 2, -1);
	else if (keycode == KEY_F)
		color_switch(f, 1, -1);
	else if (keycode == KEY_V)
		color_switch(f, 0, -1);
}

/* key_hook :
	call the different functions with the right parameters depending
	on the key pressed :
	ESCAPE to end the program
	W or UP to move up
	S or DOWN to move down
	A or LEFT to move left
	D or RIGHT to move right
	PLUS for zooming in
	MINUS for zooming out
*/
int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		end_fractol(f);
	else if (keycode == KEY_W | keycode == KEY_UP)
		move(f, 0.2, 'U');
	else if (keycode == KEY_S | keycode == KEY_DOWN)
		move(f, 0.2, 'D');
	else if (keycode == KEY_A | keycode == KEY_LEFT)
		move(f, 0.2, 'L');
	else if (keycode == KEY_D | keycode == KEY_RIGHT)
		move(f, 0.2, 'R');
	else if (keycode == KEY_PLUS | keycode == KEY_PLUS_NUMPAD)
		zoom(f, 0.5);
	else if (keycode == KEY_MINUS | keycode == KEY_MINUS_NUMPAD)
		zoom(f, 2.0);
	key_hook_fractal(keycode, f);
	key_hook_color(keycode, f);
	render(f);
	return (0);
}
