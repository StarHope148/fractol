/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:03:36 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/01 17:55:44 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    mandelbrot(t_env *frct)
{
    int 	max = 100;
    int    	x = 0;
    int		y = 0;
    
	double x1 = -2;

	double y1 = -2;

	double zoom = 150;
    while (y < frct->height)
	{
		x = 0;
		while (x < frct->width)
		{
				
			double 	c_r = x / zoom + x1;
			double 	c_i = y / zoom + y1;
			double 	z_r = 0;
			double 	z_i = 0;
			int		n = 0;
			while (n < max)
			{
				double tmp = z_r;
				z_r = z_r*z_r - z_i*z_i + c_r;
				z_i = 2*z_i*tmp + c_i;
				n++;
				if (z_r*z_r + z_i*z_i > 4)
					break;
			}
			if (n == max)
				frct->data[y * frct->width + x] = WHITE;
			else if (n < max)
				frct->data[y * frct->width + x] = BLACK;
			else
				frct->data[y * frct->width + x] = RED;
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