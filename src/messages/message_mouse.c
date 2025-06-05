/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:46:28 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/05 17:29:37 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* print_julia :
	Print message for Julia parameters modification
*/
void	print_julia(t_fractol *f)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Julia parameters changed, new values are : \n", 1);
	ft_printf("real part : %f\n", f->julia_r);
	ft_printf("imaginary part : %f\n", f->julia_i);
}

/* print_zoom :
	Print message for zoom
*/
void	print_zoom(t_fractol *f, double distance)
{
	ft_putstr_fd("\n", 1);
	if (distance < 1)
		ft_putstr_fd("Zoomed in, new frames values are : \n", 1);
	else
		ft_putstr_fd("Zoomed out, new frames values are : \n", 1);
	ft_printf("minimum real axis : %f\n", f->min_r);
	ft_printf("maximum real axis : %f\n", f->max_r);
	ft_printf("minimum imaginary axis : %f\n", f->min_i);
	ft_printf("maximum imaginary axis : %f\n", f->max_i);
}
