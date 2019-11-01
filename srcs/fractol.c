/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:04:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/01 17:14:34 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_init_env(t_env *fdf)
{
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->img_ptr = NULL;
	fdf->data = NULL;
	fdf->width = 500;
	fdf->height = 500;
	fdf->bpp = 0;
	fdf->size_l = 0;
	fdf->endian = 0;
	fdf->fractal = 0;
	fdf->iter = 0;
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
