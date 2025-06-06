/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:13:51 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 15:32:23 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* x_hook :
	simply close the program when clicking the x button
*/
int	x_hook(t_fractol *f)
{
	print_progend();
	end_fractol(f, NULL, 0);
	return (0);
}

/* zoom :
	zoom expressed in % of the frame
*/
void	zoom(t_fractol *f, double distance)
{
	f->frame_r *= distance;
	f->frame_i *= distance;
	if (distance < 1)
	{
		f->iter += STEP_ITER;
		if (f->iter > MAX_ITER)
			f->iter = MAX_ITER;
		f->zoom++;
	}
	else
	{
		f->iter -= STEP_ITER;
		if (f->iter < MIN_ITER)
			f->iter = MIN_ITER;
		f->zoom--;
	}
	print_zoom(f, distance);
}

/* key_hook_fractal :
	sub function to handle fractal type changes keyboard inputs
*/
void	key_hook_fractal(int keycode, t_fractol *f)
{
	if (keycode == KEY_1 || keycode == KEY_1_NUMPAD)
		f->f_type = MANDELBROT;
	else if (keycode == KEY_2 || keycode == KEY_2_NUMPAD)
		f->f_type = JULIA;
	else if (keycode == KEY_3 || keycode == KEY_3_NUMPAD)
		f->f_type = BURNING_SHIP;
	else if (keycode == KEY_4 || keycode == KEY_4_NUMPAD)
		f->f_type = PHOENIX;
	else if (keycode == KEY_5 || keycode == KEY_5_NUMPAD)
		f->f_type = MANOWAR;
	else
		return ;
	print_fchange(f);
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
		x_hook(f);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move(f, 0.2, 'U', 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move(f, 0.2, 'D', 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move(f, 0.2, 'L', 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move(f, 0.2, 'R', 1);
	else if (keycode == KEY_PLUS || keycode == KEY_PLUS_NUMPAD)
		zoom(f, 0.5);
	else if (keycode == KEY_MINUS || keycode == KEY_MINUS_NUMPAD)
		zoom(f, 2.0);
	else if (keycode == KEY_P)
	{
		f->psych_color = (f->psych_color + 1) % 2;
		print_pmode(f);
	}
	else if (keycode == KEY_M)
		print_command();
	key_hook_fractal(keycode, f);
	key_hook_color(keycode, f);
	render(f);
	return (0);
}
