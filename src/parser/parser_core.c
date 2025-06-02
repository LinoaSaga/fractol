/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:14:49 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/02 19:19:59 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ft_atod_numpart :
	dummy function splitting atod in two parts, just for numbers of lines
	directly modify the variables created in atod
*/
void	ft_atod_sign(char *str, size_t *i, double *sign)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		*sign = 44 - str[*i];
		(*i)++;
	}
}

/* ft_atod :
	get the input inside a double, returns 1 in case of success, 0 if input
	was incorrect. Given that for Julia relevant numbers are between -2 and +2,
	we don't bother handling overflow (what are you even doing ?)
*/
char	ft_atod(char *str, double *n)
{
	double	sign;
	double	div;
	size_t	i;

	*n = 0.0;
	sign = 1.0;
	i = 0;
	ft_atod_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		*n = *n * 10.0 + (str[i] - '0') * sign;
		i++;
	}
	if (str[i] == '.')
		i++;
	div = 0.1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*n += (str[i] - '0') * sign * div;
		div *= 0.1;
		i++;
	}
	if (str[i])
		return (0);
	return (1);
}

/* get_julia :
	handle the possibility of indicating a complex number when fractal type
	is julia. Program ends in case of reading problem
*/
void	get_julia(t_fractol *f, int argc, char **argv)
{
	if (f->f_type != JULIA && f->f_type != PHOENIX && f->f_type != MANOWAR)
		return ;
	else if (f->f_type == JULIA && argc < 4)
	{
		f->julia_r = -0.8;
		f->julia_i = 0.156;
	}
	else if (f->f_type == PHOENIX && argc < 4)
	{
		f->julia_r = 0.56667;
		f->julia_i = 0;
	}
	else if (f->f_type == MANOWAR && argc < 4)
	{
		f->julia_r = -0.01;
		f->julia_i = 0;
	}
	else
	{
		if (!ft_atod(argv[2], &(f->julia_r))
			|| !ft_atod(argv[3], &(f->julia_i)))
			end_fractol(f);
	}
}

/* get_f_type :
	Program ends if input is not recognised, also double check that the
	number of arguments is correct given the fractal type
*/
void	get_f_type(t_fractol *f, int argc, char **argv)
{
	char	*s;

	s = argv[1];
	if (!ft_strcmp(s, "mandelbrot") || !ft_strcmp(s, "1"))
		f->f_type = MANDELBROT;
	else if (!ft_strcmp(s, "julia") || !ft_strcmp(s, "2"))
		f->f_type = JULIA;
	else if (!ft_strcmp(s, "burning") || !ft_strcmp(s, "3"))
		f->f_type = BURNING_SHIP;
	else if (!ft_strcmp(s, "phoenix") || !ft_strcmp(s, "4"))
		f->f_type = PHOENIX;
	else if (!ft_strcmp(s, "manowar") || !ft_strcmp(s, "5"))
		f->f_type = MANOWAR;
	if (f->f_type == -1)
		end_fractol(f);
	else if ((f->f_type == JULIA || f->f_type == PHOENIX
			|| f->f_type == MANOWAR) && argc > 5)
		end_fractol(f);
	else if ((f->f_type == MANDELBROT || f->f_type == BURNING_SHIP)
		&& argc > 3)
		end_fractol(f);
}

/* get_inputs :
	verify we have the correct number of arguments and do the parsing
	for Julia set, we can specify the complex number as a double
	End the program in case of invalid parameters
*/
void	get_inputs(t_fractol *f, int argc, char **argv)
{
	if (argc == 1)
	{
		f->f_type = MANDELBROT;
		f->color = COLOR_EMERALD_SEA;
		return ;
	}
	get_f_type(f, argc, argv);
	get_julia(f, argc, argv);
	get_color(f, argc, argv);
}
