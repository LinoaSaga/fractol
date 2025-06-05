/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:51:44 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/03 12:11:32 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ft_atocolor:
	convert the string input into an int representing a color
	verify that the string is of the form 0xRRGGBB, otherwise end the program
	else convert it thanks to base 16 in int
*/
void	ft_atocolor(t_fractol *f, char *s, char *base)
{
	int		num;
	size_t	k;

	if (ft_strlen(s) != 8)
		end_fractol(f, "Invalid color format, see help below :", 1);
	if (s[0] != '0' || s[1] != 'x')
		end_fractol(f, "Invalid color format, see help below :", 1);
	num = 0;
	k = 1;
	while (++k < 8)
	{
		if (ft_strchrind(base, s[k]) == (size_t) - 1)
			end_fractol(f, "Invalid color format, see help below :", 1);
		num = num * 16 + ft_strchrind(base, s[k]);
	}
	f->color = num;
}

/* get_color:
	parse the main color used to define the palette later on
*/
void	get_color(t_fractol *f, int argc, char **argv)
{
	if (f->f_type == MANDELBROT || f->f_type == BURNING_SHIP)
	{
		if (argc == 2)
			f->color = COLOR_EMERALD_SEA;
		else
			ft_atocolor(f, argv[2], "0123456789abcdef");
	}
	else if (f->f_type == JULIA || f->f_type == PHOENIX || f->f_type == MANOWAR)
	{
		if (argc == 2 || argc == 4)
			f->color = COLOR_EMERALD_SEA;
		else if (argc == 3)
			ft_atocolor(f, argv[2], "0123456789abcdef");
		else
			ft_atocolor(f, argv[4], "0123456789abcdef");
	}
}
