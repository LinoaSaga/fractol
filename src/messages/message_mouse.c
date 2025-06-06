/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:46:28 by ljudd             #+#    #+#             */
/*   Updated: 2025/06/06 15:21:59 by ljudd            ###   ########.fr       */
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
	(void) f;
	ft_printf("center real axis : %f\n", f->center_r);
	ft_printf("center imaginary axis : %f\n", f->center_i);
	ft_printf("zoom level : %d\n", f->zoom);
}
