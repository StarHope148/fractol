/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:03:36 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/02 19:40:11 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_rgb(int r, int g, int b)
{
	r *= 256 * 256;
	g *= 256;
	return (r + g + b);
}

void	ft_color(t_env *frct, int n, int x, int y)
{
	if (n == frct->itermax)
		frct->data[y * frct->width + x] = BLACK;
	else if (frct->colormod == BLUE_MOD)
		frct->data[y * frct->width + x] = ft_rgb(0, 0, n * 255 / frct->itermax);
	else if (frct->colormod == RED_MOD)
		frct->data[y * frct->width + x] = ft_rgb(n * 255 / frct->itermax, 0, 0);
	else if (frct->colormod == GREEN_MOD)
		frct->data[y * frct->width + x] = ft_rgb(0, n * 255 / frct->itermax, 0);
		/* else if (n > frct->itermax * 0.90)
			frct->data[y * frct->width + x] = DARK_BLUE;
		else if (n > frct->itermax * 0.70)
			frct->data[y * frct->width + x] = BLUE;
		else if (n > frct->itermax * 0.50)
			frct->data[y * frct->width + x] = CYAN;
		else
			frct->data[y * frct->width + x] = BLACK; */
}

void    mandelbrot(t_env *frct)
{
    int    	x = 0;
    int		y = 0;
    int		n;
	t_complex val;
	double tmp;
	
    while (y < frct->height)
	{
		x = 0;
		while (x < frct->width)
		{
				
			val.c_r = x / frct->zoom + frct->cx;
			val.c_i = y / frct->zoom + frct->cy;
			val.z_r = 0;
			val.z_i = 0;
			n = 0;
			while (n < frct->itermax)
			{
				tmp = val.z_r;
				val.z_r = val.z_r * val.z_r - val.z_i * val.z_i + val.c_r;
				val.z_i = 2 * val.z_i * tmp + val.c_i;
				n++;
				if (val.z_r * val.z_r + val.z_i * val.z_i > 4)
					break;
			}
			ft_color(frct, n, x, y);
			
			x++;
		}
		y++;
	}
/* 	// on définit la zone que l'on dessine. Ici, la fractale en entière
	définir x1 = -2.1
	définir x2 = 0.6
	définir y1 = -1.2
	définir y2 = 1.2
	définir zoom = 100 // pour une distance de 1 sur le plan, on a 100 pixel sur l'image
	définir iteration_max = 50

	// on calcule la taille de l'image :
	définir image_x = (x2 - x1) * zoom
	définir image_y = (y2 - y1) * zoom

	Pour x = 0 tant que x < image_x par pas de 1 
		Pour y = 0 tant que y < image_y par pas de 1
			définir c_r = x / zoom + x1
			définir c_i = y / zoom + y1
			définir z_r = 0
			définir z_i = 0
			définir i = 0

			Faire
				définir tmp = z_r
				z_r = z_r*z_r - z_i*z_i + c_r
				z_i = 2*z_i*tmp + c_i
				i = i+1
			Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

			si i = iteration_max
				dessiner le pixel de coordonné (x; y)
			finSi
		finPour
	finPour */
}