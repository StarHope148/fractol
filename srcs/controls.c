/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:25:14 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 19:03:33 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_iteration(t_env *frct, int keycode)
{
	if (keycode == MORE)
		frct->itermax++;
	else if (frct->itermax > 0)
		frct->itermax--;
}

void	ft_move(t_env *frct, int keycode)
{
	if (frct->fractal != BURNINGSHIP)
	{
		if (keycode == LEFT_ARROW)
			frct->hor -= MOVE_SPEED * frct->zoom;
		else if (keycode == RIGHT_ARROW)
			frct->hor += MOVE_SPEED * frct->zoom;
		else if (keycode == UP_ARROW)
			frct->vert += MOVE_SPEED * frct->zoom;
		else if (keycode == DOWN_ARROW)
			frct->vert -= MOVE_SPEED * frct->zoom;
	}
	else
	{
		if (keycode == LEFT_ARROW)
			frct->hor -= MOVE_SPEED * frct->zoom;
		else if (keycode == RIGHT_ARROW)
			frct->hor += MOVE_SPEED * frct->zoom;
		else if (keycode == UP_ARROW)
			frct->vert -= MOVE_SPEED * frct->zoom;
		else if (keycode == DOWN_ARROW)
			frct->vert += MOVE_SPEED * frct->zoom;
	}
}

void	ft_zoom(t_env *frct, int keycode)
{
	if (keycode == TWO_NUM_PAD)
		frct->zoom *= ZOOM_SPEED;
	else
		frct->zoom *= 1.0 / ZOOM_SPEED;
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
	if (frct->fractal == 4)
		frct->fractal = 0;
	else
		frct->fractal++;
	ft_init_fractal(frct);
	if (frct->fractal != JULIA)
		frct->motion = 0;
}
