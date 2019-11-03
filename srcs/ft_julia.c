/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:31:36 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 19:02:30 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_env *frct)
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
			v.xn = (x * (frct->xmax - frct->xmin) / frct->width * frct->zoom + frct->xmin) + frct->hor;
			v.yn = (y * (frct->ymin - frct->ymax) / frct->height * frct->zoom + frct->ymax) + frct->vert;
			v.cx = frct->mouse.y * 0.005;
			v.cy = frct->mouse.x * 0.005;
			n = 0;
			while (((v.xn * v.xn + v.yn * v.yn) < 4) && (n < frct->itermax))
			{
				tmp_x = v.xn;
				v.xn = tmp_x * tmp_x - v.yn * v.yn + v.cx;
				v.yn = 2 * tmp_x * v.yn + v.cy;
				n++;
			}
			ft_color(frct, n, x, y);
			x++;
		}
		y++;
	}
}

