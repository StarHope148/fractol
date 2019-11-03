/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:04:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 21:42:47 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_init_fractal(t_env *frct)
{
	if (frct->fractal == MANDELBROT)
	{
		frct->xmin = -2.5;
		frct->xmax = 0.5;
		frct->ymin = -1.25;
		frct->ymax = 1.25;
		frct->hor = 0;
		frct->vert = 0;
	}
	else if (frct->fractal == JULIA)
	{
		frct->xmin = -1.25;
		frct->xmax = 1.25;
		frct->ymin = -1.25;
		frct->ymax = 1.25;
		frct->hor = 0;
		frct->vert = 0;
	}
	else if (frct->fractal == BURNINGSHIP)
	{
		frct->xmin = -0.05;
		frct->xmax = 0.05;
		frct->ymin = 0.05;
		frct->ymax = -0.05;
		frct->hor = -1.75;
		frct->vert = -0.035;
	}
}

void		ft_default(t_env *frct)
{
	frct->itermax = 50;
	frct->hor = 0;
	frct->vert = 0;
	frct->zoom = 1;
	ft_init_fractal(frct);
}

void		ft_init_env(t_env *frct)
{
	frct->mlx_ptr = NULL;
	frct->win_ptr = NULL;
	frct->img_ptr = NULL;
	frct->data = NULL;
	frct->width = WIDTH;
	frct->height = HEIGHT;
	frct->bpp = 0;
	frct->size_l = 0;
	frct->endian = 0;
	frct->fractal = 0;
	frct->itermax = 50;
	frct->n = 0;
	frct->hor = 0;
	frct->vert = 0;
	frct->zoom = 1;
	frct->colormod = BLUE_MOD;
	frct->motion = 0;
	frct->mouse.x = 2;
	frct->mouse.y = 57;
}

void		ft_controls_console(void)
{
	ft_putstr("\033[1;31m ----------------------------------------");
	ft_putstr("--------------------------------------------------\n");
	ft_putendl("\033[1;34m ITERATION MAX		:\033[1;32m [+][-] num_pad");
	ft_putendl("\033[1;34m ZOOM			:\033[1;32m scroll");
	ft_putendl("\033[1;34m NAVIGATE		:\033[1;32m arrows");
	ft_putendl("\033[1;34m ACTIVATE CURSOR PARAM	:\033[1;32m left click");
	ft_putendl("\033[1;34m RESET VIEW		:\033[1;32m [0] num_pad");
	ft_putendl("\033[1;34m CHANGE COLOR		:\033[1;32m [3] num_pad");
	ft_putendl("\033[1;34m CHANGE FRACTAL		:\033[1;32m [5] num_pad");
	ft_putstr("\033[1;31m ----------------------------------------");
	ft_putstr("--------------------------------------------------\n");
}

int			ft_fractol(char *fractal)
{
	t_env		frct;

	ft_init_env(&frct);
	if (ft_strcmp(fractal, "Mandelbrot") == 0
			|| ft_strcmp(fractal, "mandelbrot") == 0)
		frct.fractal = MANDELBROT;
	else if (ft_strcmp(fractal, "Julia") == 0
			|| ft_strcmp(fractal, "julia") == 0)
		frct.fractal = JULIA;
	else if (ft_strcmp(fractal, "Burningship") == 0
			|| ft_strcmp(fractal, "burningship") == 0)
		frct.fractal = BURNINGSHIP;
	else
		return (ft_usage());
	ft_init_fractal(&frct);
	ft_controls_console();
	if (ft_mlx(&frct) == -1)
		return (-1);
	return (0);
}
