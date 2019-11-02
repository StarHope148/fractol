/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:37:25 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/02 19:50:36 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom_mouse(int mousekey, int x, int y, t_env *frct)
{
	(void)x;
	(void)y;
	double oldzoom;

	oldzoom = frct->zoom;
	if (mousekey == MOUSE_SCROLL_UP)
	{
		frct->zoom *= 1.05;
		frct->cx /= 1.038;
		frct->cy /= 1.05;
	}
	else if (mousekey == MOUSE_SCROLL_DOWN)
	{
		frct->zoom *= 1.0 / 1.05;
		frct->cx *= 1.038;
		frct->cy *= 1.05;
	}
	printf("cx = %.2f\t\tzoom = %.2f\ncy = %.2f\n\n", frct->cx, frct->zoom, frct->cy);		//DEBUG
}
/* 
new_map_x = map_x - (cursor_x / screen_max_width * (new_map_width - map_width))
new_map_y = map_y - (cursor_y / screen_max_height * (new_map_height - map_height))

----------> screen_x = map_x * zoom
*/
int		ft_mouse_hook(int mousekey, int x, int y, t_env *frct)
{
	if (mousekey == MOUSE_SCROLL_UP || mousekey == MOUSE_SCROLL_DOWN)
		ft_zoom_mouse(mousekey, x, y, frct);
	else
	{
		ft_putnbr(mousekey);
		write(1, " | at x : ", 10);
		ft_putnbr(x);
		write(1, " and y : ", 9);
		ft_putnbr(y);
		write(1, "\n", 1);
	}

	if (ft_print(frct) == -1)
		return (-1);
	return (0);
}