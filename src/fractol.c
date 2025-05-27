/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:58:17 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/26 15:46:38 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractol	f;

	c_init(&f);
	init(&f);
	render(&f);
	mlx_hook(f.win, CLOSING_X, 0L, end_fractol, &f);
	mlx_loop(f.mlx);
	return (0);
}
