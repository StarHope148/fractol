/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:37:25 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 18:37:05 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_mouse_motion(int x, int y, t_env *frct)
{
	if (frct->motion == 0)
		return (0);
	frct->mouse.x = (double)x - (double)frct->width / 2;
	frct->mouse.y = (double)y - (double)frct->height / 2;
	if (ft_print(frct) == -1)
		return (-1);
	return (0);
}

void	ft_motion_mod(t_env *frct)
{
	if (frct->fractal == JULIA)
	{
		if (frct->motion == 1)
			frct->motion = 0;
		else
			frct->motion = 1;
	}
}

int		ft_mouse_hook(int mousekey, int x, int y, t_env *frct)
{
	if (mousekey == MOUSE_SCROLL_UP || mousekey == MOUSE_SCROLL_DOWN)
		ft_zoom_mouse(mousekey, x, y, frct);
	else if (mousekey == MOUSE_LEFT)
		ft_motion_mod(frct);
	if (ft_print(frct) == -1)
		return (-1);
	return (0);
}
