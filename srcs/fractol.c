/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:04:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/02 19:24:57 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_init_env(t_env *frct)
{
	frct->mlx_ptr = NULL;
	frct->win_ptr = NULL;
	frct->img_ptr = NULL;
	frct->data = NULL;
	frct->width = WIDTH;
	frct->height = HEIGHT;
	frct->bpp = 0;
	frct->size_l = 0;
	frct->endian = 0;
	frct->fractal = 0;
	frct->itermax = 50;
	frct->cx = -2.5;
	frct->cy = -1.5;
	frct->zoom = frct->width / 4;
	frct->colormod = BLUE_MOD;
}

int			ft_fractol(char *fractal)
{
	t_env		frct;

	ft_init_env(&frct);
	if (ft_strcmp(fractal, "Sierpinski") == 0)
		frct.fractal = SIERPINSKI;
	else if (ft_strcmp(fractal, "Mandelbrot") == 0)
		frct.fractal = MANDELBROT;
	else
		return (ft_usage());
	if (ft_mlx(&frct) == -1)
		return (-1);
	return (0);
}
