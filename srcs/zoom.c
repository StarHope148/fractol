/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:39:33 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 16:46:01 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom_out(t_env *frct, int x, int y)
{
	frct->zoom *= ZOOM_SPEED;
	if (frct->fractal != BURNINGSHIP)
	{
		if (x > 0)
			frct->hor -= MOVE_SPEED * frct->zoom * x * MOUSE_S;
		else
			frct->hor += MOVE_SPEED * frct->zoom * fabs((double)x) * MOUSE_S;
		if (y > 0)
			frct->vert += MOVE_SPEED * frct->zoom * y * MOUSE_S;
		else
			frct->vert -= MOVE_SPEED * frct->zoom * fabs((double)y) * MOUSE_S;
	}
	else
	{
		if (x > 0)
			frct->hor -= MOVE_SPEED * frct->zoom * x * MOUSE_S;
		else
			frct->hor += MOVE_SPEED * frct->zoom * fabs((double)x) * MOUSE_S;
		if (y > 0)
			frct->vert -= MOVE_SPEED * frct->zoom * y * MOUSE_S;
		else
			frct->vert += MOVE_SPEED * frct->zoom * fabs((double)y) * MOUSE_S;
	}
}

void	ft_zoom_in(t_env *frct, int x, int y)
{
	frct->zoom *= 1.0 / ZOOM_SPEED;
	if (frct->fractal != BURNINGSHIP)
	{
		if (x > 0)
			frct->hor += MOVE_SPEED * frct->zoom * x * MOUSE_S;
		else
			frct->hor -= MOVE_SPEED * frct->zoom * fabs((double)x) * MOUSE_S;
		if (y > 0)
			frct->vert -= MOVE_SPEED * frct->zoom * y * MOUSE_S;
		else
			frct->vert += MOVE_SPEED * frct->zoom * fabs((double)y) * MOUSE_S;
	}
	else
	{
		if (x > 0)
			frct->hor += MOVE_SPEED * frct->zoom * x * MOUSE_S;
		else
			frct->hor -= MOVE_SPEED * frct->zoom * fabs((double)x) * MOUSE_S;
		if (y > 0)
			frct->vert += MOVE_SPEED * frct->zoom * y * MOUSE_S;
		else
			frct->vert -= MOVE_SPEED * frct->zoom * fabs((double)y) * MOUSE_S;
	}
}

void	ft_zoom_mouse(int mousekey, int x, int y, t_env *frct)
{
	x -= frct->width / 2;
	y -= frct->height / 2;
	if (mousekey == MOUSE_SCROLL_DOWN)
	{
		ft_zoom_out(frct, x, y);
	}
	else if (mousekey == MOUSE_SCROLL_UP)
	{
		ft_zoom_in(frct, x, y);
	}
}
