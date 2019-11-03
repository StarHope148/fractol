/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:10:27 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 18:23:36 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot(t_env *frct)
{
	int  	  	x;
    int			y;
	double 		tmp_x;
	t_complex2 	v;
	int			n;

	y = 0;
    while (y < frct->height)
	{
		x = 0;
		while (x < frct->width)
		{
			v.cx = (x * (XMAX - XMIN) / frct->width * frct->zoom + XMIN) + frct->hor;
			v.cy = (y * (YMIN - YMAX) / frct->height * frct->zoom + YMAX) + frct->vert;
			v.xn = 0;
			v.yn = 0;
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
/*
# Constantes
MAX_ITERATION = 50 # nombre d'itérations maximales avant de considérer que la suite converge
XMIN, XMAX, YMIN, YMAX = -2, +0.5, -1.25, +1.25 # bornes du repère

for y in range(HAUTEUR):
  for x in range(LARGEUR):
    # Les deux lignes suivantes permettent d'associer à chaque pixel de l'écran de coordonnées (x;y)
    # un point C du plan de coordonnées (cx;cy) dans le repère défini par XMIN:XMAX et YMIN:YMAX
    cx = (x * (XMAX - XMIN) / LARGEUR + XMIN)		-> v.c_r
    cy = (y * (YMIN - YMAX) / HAUTEUR + YMAX)		-> v.c_i
    xn = 0											-> v.z_r
    yn = 0											-> v.z_i
    n = 0
    while (xn * xn + yn * yn) < 4 and n < MAX_ITERATION: # on teste que le carré de la distance est inférieur à 4 -> permet d'économiser un calcul de racine carrée coûteux en terme de performances
      # Calcul des coordonnes de Mn
      tmp_x = xn
      tmp_y = yn
      xn = tmp_x * tmp_x - tmp_y * tmp_y + cx
      yn = 2 * tmp_x * tmp_y + cy
      n = n + 1
    if n == MAX_ITERATION:
      screen.set_at((x, y), (0, 0, 0)) # On colore le pixel en noir -> code RGB : (0,0,0)
    else:
      screen.set_at((x, y), (255, 255, 255)) # On colore le pixel en blanc -> code RGB : (255,255,255)


	  XMIN, XMAX, YMIN, YMAX = -1.8, -1.7, -0.05, 0.05

*/