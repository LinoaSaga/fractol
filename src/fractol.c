/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:58:17 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/05 10:41:46 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* end_fractol :
	clean the different objects (if they exist) + exit the program
	
*/
int	end_fractol(t_fractol *f, char *msg, char display_help)
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
	if (msg)
		ft_putendl_fd(msg, 2);
	if (display_help)
		print_help();
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	print_header();
	c_init(&f);
	get_inputs(&f, argc, argv);
	init(&f);
	render(&f);
	mlx_hook(f.win, CLOSING_X, 0L, x_hook, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
