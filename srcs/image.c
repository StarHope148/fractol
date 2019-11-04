/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 18:37:22 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_ui_next(t_env *frct)
{
	char	*x_coord;
	char	*y_coord;

	if ((x_coord = ft_itoa(frct->mouse.x)) == NULL)
		ft_exit(frct);
	if ((y_coord = ft_itoa(frct->mouse.y)) == NULL)
	{
		free(x_coord);
		ft_exit(frct);
	}
	mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
					frct->height * 0.08, GRAY, "X :");
	mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.06,
					frct->height * 0.08, GRAY, x_coord);
	mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
					frct->height * 0.1, GRAY, "Y :");
	mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.06,
					frct->height * 0.1, GRAY, y_coord);
	free(x_coord);
	free(y_coord);
}

void	ft_show_motion_mod(t_env *frct)
{
	if (frct->motion == 0)
		mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
						frct->height * 0.06, GRAY, "MOTION OFF");
	else
		mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
						frct->height * 0.06, GRAY, "MOTION ON");
}

void	ft_ui(t_env *frct)
{
	char	*iter;

	iter = ft_itoa(frct->itermax);
	if (frct->fractal == MANDELBROT)
		mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
						frct->height * 0.01, DODGER_BLUE, "MANDELBROT SET");
	else if (frct->fractal == JULIA)
		mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
						frct->height * 0.01, DODGER_BLUE, "JULIA SET");
	else if (frct->fractal == BURNINGSHIP)
		mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
						frct->height * 0.01, DODGER_BLUE, "BURNINGSHIP SET");
	else if (frct->fractal == MULTIBROT)
		mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
						frct->height * 0.01, DODGER_BLUE, "MULTIBROT 2 SET");
	else if (frct->fractal == TRICORN)
		mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
						frct->height * 0.01, DODGER_BLUE, "TRICORN SET");
	mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.02,
					frct->height * 0.04, GRAY, "ITERATIONS :");
	mlx_string_put(frct->mlx_ptr, frct->win_ptr, frct->width * 0.15,
					frct->height * 0.04, GRAY, iter);
	free(iter);
	ft_show_motion_mod(frct);
	ft_ui_next(frct);
}

int		ft_print(t_env *frct)
{
	if (frct->img_ptr == NULL)
	{
		frct->img_ptr = mlx_new_image(frct->mlx_ptr,
										frct->width, frct->height);
		if (frct->img_ptr == NULL)
			return (-1);
		frct->data = (int *)mlx_get_data_addr(frct->img_ptr, &frct->bpp,
												&frct->size_l, &frct->endian);
		if (frct->data == NULL)
			return (-1);
	}
	ft_draw(frct);
	mlx_put_image_to_window(frct->mlx_ptr, frct->win_ptr, frct->img_ptr, 0, 0);
	ft_ui(frct);
	return (0);
}

int		ft_draw(t_env *frct)
{
	if (frct->fractal == MANDELBROT)
		ft_mandelbrot(frct);
	else if (frct->fractal == JULIA)
		ft_julia(frct);
	else if (frct->fractal == BURNINGSHIP)
		ft_burningship(frct);
	else if (frct->fractal == MULTIBROT)
		ft_mandelbrot_duo(frct);
	else if (frct->fractal == TRICORN)
		ft_tricorn(frct);
	return (0);
}
