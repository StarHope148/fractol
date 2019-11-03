/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 18:15:30 by jcanteau         ###   ########.fr       */
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
	//ft_bzero(frct->data, frct->width * frct->height * 4);
 	ft_link_points(frct);
	mlx_put_image_to_window(frct->mlx_ptr, frct->win_ptr, frct->img_ptr, 0, 0);
	return (0);
}

void	ft_lines(t_env *frct)						//DEBUG
{
	int		x;
	int		y;

	y = 0;
	while (y < frct->height)
	{
		x = 0;
		while (x < frct->width)
		{
			if (y == frct->height / 2)
				frct->data[y * frct->width + x] = YELLOW;
			else if (x == frct->width / 2)
				frct->data[y * frct->width + x] = YELLOW;
			x++;
		}
		y++;
	}
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
		ft_sierpinski(frct, pA, pB, pC, frct->itermax);
	else if (frct->fractal == MANDELBROT)
		ft_mandelbrot(frct);
	else if (frct->fractal == JULIA)
		ft_julia(frct);

	//ft_lines(frct);
	return (0);
}
