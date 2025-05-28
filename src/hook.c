/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:56:34 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/28 14:18:44 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* end_fractol :
	clean the different objects (if they exist) +
	exit the program
*/
int	end_fractol(t_fractol *f)
{
	if (!f)
		return (0);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
	{
		mlx_destroy_window(f->mlx, f->win);
		f->win = NULL;
	}
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	if (f->palette)
		free(f->palette);
	exit(0);
	return (0);
}

/* move :
	move accordingly to a distance expressed in % of the range and
	a direction (U, D, L, R)
*/
void	move(t_fractol *f, double distance, char direction)
{
	double	range_r;
	double	range_i;

	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	if (direction == 'U')
	{
		f->max_i -= range_i * distance;
		f->min_i -= range_i * distance;
	}
	if (direction == 'D')
	{
		f->max_i += range_i * distance;
		f->min_i += range_i * distance;
	}
	if (direction == 'L')
	{
		f->max_r -= range_r * distance;
		f->min_r -= range_r * distance;
	}
	if (direction == 'R')
	{
		f->max_r += range_r * distance;
		f->min_r += range_r * distance;
	}
}

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

/* key_hook :
	call the different functions with the right parameters depending
	on the key pressed :
	ESCAPE to end the program
	W or UP to move up
	S or DOWN to move down
	A or LEFT to move left
	D or RIGHT to move right
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
	render(f);
	return (0);
}

/* key_hook :
	call the different functions with the right parameters depending
	on the button pressed :
	RIGHT CLICK or SCROLL DOWN to zoom out
	LEFT CLICK or SCROLL UP to zoom in
	For zoom in, we also move the range as such that the point of zoom
	becomes the new center of the screen
*/
int	mouse_hook(int keycode, int x, int y, t_fractol *f)
{
	double	range_p_r;
	double	range_p_i;

	if (keycode == RIGHT_CLICK | keycode == SCROLL_DOWN)
		zoom(f, 2.0);
	if (keycode == LEFT_CLICK | keycode == SCROLL_UP)
	{
		range_p_r = (WIDTH / 2.0 - x) / WIDTH;
		range_p_i = (HEIGHT / 2.0 - y) / HEIGHT;
		if (range_p_r < 0)
			move(f, -range_p_r, 'R');
		else
			move(f, range_p_r, 'L');
		if (range_p_i < 0)
			move(f, -range_p_i, 'D');
		else
			move(f, range_p_i, 'U');
		zoom(f, 0.5);
	}
	render(f);
	return (0);
}
