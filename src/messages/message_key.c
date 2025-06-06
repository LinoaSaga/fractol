/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:46:31 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 15:22:06 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* print_progend :
	Print message when program closed succesfully
*/
void	print_progend(void)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Program ended normally :)\n", 1);
}

/* print_move :
	Print message when moving the frame
*/
void	print_move(t_fractol *f, char direction)
{
	ft_putstr_fd("\n", 1);
	if (direction == 'U')
		ft_putstr_fd("Moved up, new frames values are : \n", 1);
	if (direction == 'D')
		ft_putstr_fd("Moved down, new frames values are : \n", 1);
	if (direction == 'L')
		ft_putstr_fd("Moved left, new frames values are : \n", 1);
	if (direction == 'R')
		ft_putstr_fd("Moved right, new frames values are : \n", 1);
	(void) f;
	ft_printf("center real axis : %f\n", f->center_r);
	ft_printf("center imaginary axis : %f\n", f->center_i);
	ft_printf("zoom level : %d\n", f->zoom);
}

/* print_pmode :
	Print message for psycho color mode
*/
void	print_pmode(t_fractol *f)
{
	ft_putstr_fd("\n", 1);
	if (f->psych_color)
		ft_putstr_fd("Psychedelic color mode enabled\n", 1);
	else
		ft_putstr_fd("Psychedelic color mode disabled\n", 1);
}

/* print_cswitch :
	Print message for color switch
*/
void	print_cswitch(t_fractol *f, size_t color, int incr)
{
	int	rgb[3];

	rgb[0] = (f->color) & 0xff;
	rgb[1] = (f->color >> 8) & 0xff;
	rgb[2] = (f->color >> 16) & 0xff;
	ft_putstr_fd("\n", 1);
	if (color == 0 && incr > 0)
		ft_putstr_fd("Blue value increased, new color used is :", 1);
	else if (color == 0 && incr < 0)
		ft_putstr_fd("Blue value decreased, new color used is :", 1);
	else if (color == 1 && incr > 0)
		ft_putstr_fd("Green value increased, new color used is :", 1);
	else if (color == 1 && incr < 0)
		ft_putstr_fd("Green value decreased, new color used is :", 1);
	else if (color == 2 && incr > 0)
		ft_putstr_fd("Red value increased, new color used is :", 1);
	else if (color == 2 && incr < 0)
		ft_putstr_fd("Red value decreased, new color used is :", 1);
	ft_printf(" 0x%02x%02x%02x\n", rgb[2], rgb[1], rgb[0]);
}

/* print_fchange :
	Print message for fractal change
*/
void	print_fchange(t_fractol *f)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Fractal type changed, new fractal type is : ", 1);
	if (f->f_type == MANDELBROT)
		ft_putstr_fd("Mandelbrot set\n", 1);
	else if (f->f_type == JULIA)
		ft_putstr_fd("Julia set\n", 1);
	else if (f->f_type == BURNING_SHIP)
		ft_putstr_fd("Burning Ship set\n", 1);
	else if (f->f_type == PHOENIX)
		ft_putstr_fd("Phoenix set\n", 1);
	else
		ft_putstr_fd("Man O War set\n", 1);
}
