/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:58:04 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/05 12:37:16 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* print_header :
	Print the main header in the display for fractol, used at start of program
*/
void	print_header(void)
{
	ft_putendl_fd("/================================================/", 1);
	ft_putendl_fd("/                                                /", 1);
	ft_putendl_fd("/                    FRACTOL                     /", 1);
	ft_putendl_fd("/                                                /", 1);
	ft_putendl_fd("/================================================/", 1);
}

/* print_help :
	Print the input helps 
*/
void	print_help(void)
{
	ft_putstr_fd("\n\n\n", 1);
	ft_putendl_fd("/================================================/", 1);
	ft_putendl_fd("/                  PARAMETERS                    /", 1);
	ft_putendl_fd("/================================================/", 1);
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("/ Fractal type : indicate the fractal to display /", 1);
	ft_putendl_fd("/ 1 or mandelbrot : Mandelbrot set               /", 1);
	ft_putendl_fd("/ 2 or julia : Julia set                         /", 1);
	ft_putendl_fd("/ 3 or burning : Burning Ship set                /", 1);
	ft_putendl_fd("/ 4 or phoenix : Phoenix set                     /", 1);
	ft_putendl_fd("/ 5 or manowar : Manowar set                     /", 1);
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("/Complex c : two optional parameters for julia   /", 1);
	ft_putendl_fd("/ phoenix and manowar set. Take the form of two  /", 1);
	ft_putendl_fd("/ doubles for real and imaginary part,           /", 1);
	ft_putendl_fd("/ in comma format, relevant values are between -2/", 1);
	ft_putendl_fd("/ and 2. Overflow are undefined behaviours       /", 1);
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("/Color : color of the fractal fornat 0xRRGGBB    /", 1);
	ft_putendl_fd("/with RRGGBB in hexadecimal                      /", 1);
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("/================================================/", 1);
}

/* print_command :
	Print the commands availables
*/
void	print_command(void)
{
	ft_putstr_fd("\n\n\n", 1);
	ft_putendl_fd("/================================================/", 1);
	ft_putendl_fd("/                   COMMANDS                     /", 1);
	ft_putendl_fd("/================================================/", 1);
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("/ Mouse commands --------------------------------/", 1);
	ft_putendl_fd("/ right click or scroll down : zoom out at center/", 1);
	ft_putendl_fd("/ left click or scroll up : zoom in at mouse pos /", 1);
	ft_putendl_fd("/ mid click : set julia parameters at mouse pos  /", 1);
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("/ Keyboard commands -----------------------------/", 1);
	ft_putendl_fd("/ escape : exit the program                      /", 1);
	ft_putendl_fd("/ w or up : move up                              /", 1);
	ft_putendl_fd("/ s or down : move down                          /", 1);
	ft_putendl_fd("/ a or left : move left                          /", 1);
	ft_putendl_fd("/ d or right : move right                        /", 1);
	ft_putendl_fd("/ + or + numpad : zoom in at center              /", 1);
	ft_putendl_fd("/ - or - numpad : zoom out at center             /", 1);
	ft_putendl_fd("/ p : activate/desactivate psychedelic color mode/", 1);
	ft_putendl_fd("/ m : print the command message                  /", 1);
	ft_putstr_fd("\n", 1);
	ft_putendl_fd("/================================================/", 1);
}
