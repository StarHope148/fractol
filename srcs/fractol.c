/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:04:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 19:25:53 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_init_env(t_env *fdf)
{
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->img_ptr = NULL;
	fdf->data = NULL;
	fdf->width = 1000;
	fdf->height = 1000;
	fdf->bpp = 0;
	fdf->size_l = 0;
	fdf->endian = 0;
	fdf->fractal = 0;
	fdf->iter = 0;
	/* ft_init_map(fdf);
	ft_init_display(fdf);
	ft_init_menu(fdf);
	ft_init_bresenham(fdf);
	ft_init_segment_drawing_coordinate(fdf); */
}

/* void		ft_choose_focal_lenght(t_env *fdf)
{
	long	ref;

	ref = fdf->map.nbl * fdf->map.nbcol;
	if (ref < 250)
		fdf->fl = 4000;
	else if (ref < 500)
		fdf->fl = 3500;
	else if (ref < 15000)
		fdf->fl = 1000;
	else if (ref < 50000)
		fdf->fl = 500;
	else if (ref < 80000)
		fdf->fl = 300;
	else if (ref < 100000)
		fdf->fl = 250;
	else if (ref < 150000)
		fdf->fl = 200;
	else if (ref < 180000)
		fdf->fl = 150;
	else
		fdf->fl = 50;
} */

int			ft_fractol(char *fractal)
{
	t_env		frct;

	ft_init_env(&frct);
	/* if (ft_create_map(&fdf, filename) == -1)
		return (-1); */
	//ft_choose_focal_lenght(&fdf);
	if (ft_strcmp(fractal, "Sierpinski") == 0)
		frct.fractal = SIERPINSKI;
	if (frct.fractal == NONE)
		return (ft_usage());
	if (ft_mlx(&frct) == -1)
		return (-1);
	return (0);
}
