/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:25:14 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/02 18:04:25 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_iteration(t_env *frct, int keycode)
{
	if (keycode == MORE)
		frct->itermax++;
	else if (frct->itermax > 0)
		frct->itermax--;
	printf("iteration : %d\n", frct->itermax);					//DEBUG
}

void	ft_move(t_env *frct, int keycode)
{
	if (keycode == LEFT_ARROW)
			frct->cx -= MOVE;
	else if (keycode == RIGHT_ARROW)
			frct->cx += MOVE;
	else if (keycode == UP_ARROW)
			frct->cy -= MOVE;
	else if (keycode == DOWN_ARROW)
			frct->cy += MOVE;
	printf("cx = %.1f\ncy = %.1f\n\n", frct->cx, frct->cy);		//DEBUG
}

void	ft_zoom(t_env *frct, int keycode)
{
	if (keycode == ONE_NUM_PAD)
	{
		frct->zoom *= 1.05;
		frct->cx *= 1.0 / 1.05;
		frct->cy *= 1.0 / 1.05;
	}
	else
	{
		frct->zoom *= 1.0 / 1.05;
		frct->cx *= 1.05;
		frct->cy *= 1.05;
	}
}