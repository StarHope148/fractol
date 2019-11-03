/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:10:27 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 19:24:30 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_burningship(t_env *frct)
{
	int  	  	x;
    int			y;
	double 		tmp_x;
	t_complex 	v;
	int			n;

	y = 0;
    while (y < frct->height)
	{
		x = 0;
		while (x < frct->width)
		{
			v.cx = (x * (frct->xmax - frct->xmin) / frct->width * frct->zoom + frct->xmin) + frct->hor;
			v.cy = (y * (frct->ymin - frct->ymax) / frct->height * frct->zoom + frct->ymax) + frct->vert;
			v.xn = 0;
			v.yn = 0;
			n = 0;
			while (((v.xn * v.xn + v.yn * v.yn) < 4) && (n < frct->itermax))
			{
				tmp_x = v.xn;
				v.xn = fabs(tmp_x * tmp_x - v.yn * v.yn + v.cx);
				v.yn = fabs(2 * tmp_x * v.yn + v.cy);
				n++;
			}
			ft_color(frct, n, x, y);
			x++;
		}
		y++;
	}
}