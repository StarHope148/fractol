/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_duo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:01:12 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 18:24:12 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot_calc_duo(t_env *frct, int x, int y)
{
	t_complex	v;
	double		tmp;

	v.cx = (x * (frct->xmax - frct->xmin)
			/ frct->width + frct->xmin) * frct->zoom + frct->hor;
	v.cy = (y * (frct->ymin - frct->ymax)
			/ frct->height + frct->ymax) * frct->zoom + frct->vert;
	v.xn = 0;
	v.yn = 0;
	frct->n = 0;
	while (((v.xn * v.xn + v.yn * v.yn) < 4) && (frct->n < frct->itermax))
	{
		tmp = v.xn * v.xn * v.xn - 3 * v.xn * v.yn * v.yn + v.cx;
		v.yn = 3 * v.xn * v.xn * v.yn - v.yn * v.yn * v.yn + v.cy;
		v.xn = tmp;
		frct->n++;
	}
}

void	ft_mandelbrot_duo(t_env *frct)
{
	int			x;
	int			y;

	y = 0;
	while (y < frct->height)
	{
		x = 0;
		while (x < frct->width)
		{
			ft_mandelbrot_calc_duo(frct, x, y);
			ft_color(frct, frct->n, x, y);
			x++;
		}
		y++;
	}
}
