/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:10:27 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 20:52:46 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_burningship_calc(t_env *frct, int x, int y)
{
	t_complex	v;
	double		tmp;

	v.cx = (x * (frct->xmax - frct->xmin)
			/ frct->width * frct->zoom + frct->xmin) + frct->hor;
	v.cy = (y * (frct->ymin - frct->ymax)
			/ frct->height * frct->zoom + frct->ymax) + frct->vert;
	v.xn = 0;
	v.yn = 0;
	frct->n = 0;
	while (((v.xn * v.xn + v.yn * v.yn) < 4) && (frct->n < frct->itermax))
	{
		tmp = v.xn;
		v.xn = fabs(tmp * tmp - v.yn * v.yn + v.cx);
		v.yn = fabs(2 * tmp * v.yn + v.cy);
		frct->n++;
	}
}

void	ft_burningship(t_env *frct)
{
	int			x;
	int			y;

	y = 0;
    while (y < frct->height)
	{
		x = 0;
		while (x < frct->width)
		{
			ft_burningship_calc(frct, x, y);
			ft_color(frct, frct->n, x, y);
			x++;
		}
		y++;
	}
}
