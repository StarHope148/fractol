/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:04:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 18:20:01 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_default(t_env *frct)
{
	frct->itermax = 50;
	frct->hor = 0;
	frct->vert = 0;
	frct->zoom = 1;
}

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
	frct->hor = 0;
	frct->vert = 0;
	frct->zoom = 1;
	frct->colormod = BLUE_MOD;
	frct->motion = 1;
	frct->mouse.x = 0;
	frct->mouse.y = 0;
}

int			ft_fractol(char *fractal)
{
	t_env		frct;

	ft_init_env(&frct);
	if (ft_strcmp(fractal, "Sierpinski") == 0)
		frct.fractal = SIERPINSKI;
	else if (ft_strcmp(fractal, "Mandelbrot") == 0 || ft_strcmp(fractal, "mandelbrot") == 0)
		frct.fractal = MANDELBROT;
	else if (ft_strcmp(fractal, "Julia") == 0 || ft_strcmp(fractal, "julia") == 0)
		frct.fractal = JULIA;
	else
		return (ft_usage());
	if (ft_mlx(&frct) == -1)
		return (-1);
	return (0);
}
