/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:14:40 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 17:23:41 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
//bresenham(frct, A, B);

void	bresenham(t_env *frct, t_point A, t_point B)
{
	frct->dx = ft_abs(B.x - A.x);
	frct->sx = A.x < B.x ? 1 : -1;
	frct->dy = -(ft_abs(B.y - A.y));
	frct->sy = A.y < B.y ? 1 : -1;
	frct->err = frct->dx + frct->dy;
	while (1)
	{
		if ((A.y * frct->width + A.x < frct->width
				* frct->height) && (A.y >= 0 && A.x >= 0)
				&& (A.y < frct->height && A.x < frct->width))
			frct->data[A.y * frct->width + A.x] = 0xFFFFFF;
		if (A.x == B.x && A.y == B.y)
			break ;
		frct->e2 = 2 * frct->err;
		if (frct->e2 >= frct->dy)
		{
			frct->err += frct->dy;
			A.x += frct->sx;
		}
		if (frct->e2 <= frct->dx)
		{
			frct->err += frct->dx;
			A.y += frct->sy;
		}
	}
}
