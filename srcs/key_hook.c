/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:09 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 13:46:02 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_exit(t_env *frct)
{
	mlx_destroy_image(frct->mlx_ptr, frct->img_ptr);
	mlx_destroy_window(frct->mlx_ptr, frct->win_ptr);
	exit(EXIT_SUCCESS);
}

void	ft_switch_color(t_env *frct)
{
	if (frct->colormod >= RAND_MOD)
		frct->colormod = 0;
	else
		frct->colormod++;
}

void	ft_switch_fractal(t_env *frct)
{
	if (frct->fractal == BURNINGSHIP)
		frct->fractal = 0;
	else
		frct->fractal++;
	ft_init_fractal(frct);
	if (frct->fractal != JULIA)
		frct->motion = 0;
}

int		ft_key_hook(int keycode, t_env *frct)
{
	if (keycode == ESC)
		ft_exit(frct);
	else if (keycode == MORE || keycode == LESS)
		ft_iteration(frct, keycode);
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW
			|| keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		ft_move(frct, keycode);
	else if (keycode == ONE_NUM_PAD || keycode == TWO_NUM_PAD)
		ft_zoom(frct, keycode);
	else if (keycode == THREE_NUM_PAD)
		ft_switch_color(frct);
	else if (keycode == ZERO_NUM_PAD)
		ft_default(frct);
	else if (keycode == FIVE_NUM_PAD)
		ft_switch_fractal(frct);
	if (ft_print(frct) == -1)
		return (-1);
	return (0);
}
