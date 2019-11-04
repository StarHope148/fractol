/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tricorn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:18:20 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 18:28:03 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_tricorn_calc(t_env *frct, int x, int y)
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
		tmp = v.xn;
		v.xn = tmp * tmp - v.yn * v.yn + v.cx;
		v.yn = -2 * tmp * v.yn + v.cy;
		frct->n++;
	}
}

void	ft_tricorn(t_env *frct)
{
	int			x;
	int			y;

	y = 0;
	while (y < frct->height)
	{
		x = 0;
		while (x < frct->width)
		{
			ft_tricorn_calc(frct, x, y);
			ft_color(frct, frct->n, x, y);
			x++;
		}
		y++;
	}
}
