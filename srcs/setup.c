/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:08:30 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 14:17:16 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_setup_burningship(t_env *frct)
{
	frct->xmin = -1.25;
	frct->xmax = 1.25;
	frct->ymin = 1.25;
	frct->ymax = -1.25;
	frct->zoom = 0.05;
	frct->hor = -0.57;
	frct->vert = 1.15;
	frct->mouse.x = 0;
	frct->mouse.y = 0;
}

void		ft_setup_julia(t_env *frct)
{
	frct->xmin = -1.25;
	frct->xmax = 1.25;
	frct->ymin = -1.25;
	frct->ymax = 1.25;
	frct->zoom = 1;
	frct->hor = 0;
	frct->vert = 0;
	frct->mouse.x = 2;
	frct->mouse.y = 57;
}

void		ft_setup_mandelbrot(t_env *frct)
{
	frct->xmin = -2.5;
	frct->xmax = 0.5;
	frct->ymin = -1.25;
	frct->ymax = 1.25;
	frct->zoom = 1;
	frct->hor = 0.4;
	frct->vert = 0;
	frct->mouse.x = 0;
	frct->mouse.y = 0;
}

void		ft_init_fractal(t_env *frct)
{
	if (frct->fractal == MANDELBROT)
		ft_setup_mandelbrot(frct);
	else if (frct->fractal == JULIA)
		ft_setup_julia(frct);
	else if (frct->fractal == BURNINGSHIP)
		ft_setup_burningship(frct);
}
