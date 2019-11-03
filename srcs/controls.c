/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:25:14 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 20:37:52 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_iteration(t_env *frct, int keycode)
{
	if (keycode == MORE)
		frct->itermax++;
	else if (frct->itermax > 0)
		frct->itermax--;
	//printf("iteration : %d\n", frct->itermax);					//DEBUG
}

void	ft_move(t_env *frct, int keycode)
{
	if (frct->fractal == BURNINGSHIP)
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
	else
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
	//printf("hor = %.3f\t\tzoom = %.5f\nvert = %.3f\n\n", frct->hor, frct->zoom, frct->vert);		//DEBUG
}

void	ft_zoom(t_env *frct, int keycode)
{
	if (keycode == TWO_NUM_PAD)
	{
		frct->zoom *= ZOOM_SPEED;
	}
	else
	{
		frct->zoom *= 1.0 / ZOOM_SPEED;
	}
}
