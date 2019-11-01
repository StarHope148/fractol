/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/01 17:24:43 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_print(t_env *frct)
{
	if (frct->img_ptr == NULL)
	{
		frct->img_ptr = mlx_new_image(frct->mlx_ptr, frct->width, frct->height);
		if (frct->img_ptr == NULL)
			return (-1);
		frct->data = (int *)mlx_get_data_addr(frct->img_ptr, &frct->bpp,
												&frct->size_l, &frct->endian);
		if (frct->data == NULL)
			return (-1);
	}
	ft_bzero(frct->data, frct->width * frct->height * 4);
 	ft_link_points(frct);
	mlx_put_image_to_window(frct->mlx_ptr, frct->win_ptr, frct->img_ptr, 0, 0);
	return (0);
}

int		ft_link_points(t_env *frct)
{
	t_point pA;
	t_point pB;
	t_point pC;

	pA.x = frct->width * 0.1;
	pA.y = frct->height * 0.9;
	pB.x = frct->width * 0.9;
	pB.y = frct->height * 0.9;
	pC.x = frct->width * 0.5;
	pC.y = frct->height * 0.1;
	if (frct->fractal == SIERPINSKI)
		ft_sierpinski(frct, pA, pB, pC, frct->iter);
	else if (frct->fractal == MANDELBROT)
		mandelbrot(frct);
	return (0);
}
