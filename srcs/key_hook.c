/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:09 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 20:35:54 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_exit(t_env *frct)
{
/* 	int		r;

	r = 0;
	while (r < fdf->map.nbl)
	{
		free(fdf->map.tab[r]);
		free(fdf->pro[r]);
		r++;
	}
	free(fdf->map.tab);
	free(fdf->pro);
	mlx_destroy_image(fdf->mlx_ptr, fdf->menu.backmenu_ptr); */
	mlx_destroy_image(frct->mlx_ptr, frct->img_ptr);
	mlx_destroy_window(frct->mlx_ptr, frct->win_ptr);
	exit(EXIT_SUCCESS);
}

/* void	ft_switch_color(t_env *fdf)
{
	if (fdf->colormod >= CONTRAST)
		fdf->colormod = DEFAULT_MAP_COLOR;
	else
		fdf->colormod++;
	ft_color_choice(fdf);
} */

/* void	ft_switch_projection(t_env *fdf)
{
	if (fdf->projection_mod == PARA)
	{
		fdf->projection_mod = ISO;
		fdf->cx = CX_O;
		fdf->cy = CY_O;
	}
	else
	{
		fdf->projection_mod = PARA;
		fdf->cx = CX_O;
		fdf->cy = CY_O;
	}
} */

int		ft_key_hook(int keycode, t_env *frct)
{
	if (keycode == ESC)
		ft_exit(frct);
	else if (keycode == MORE || keycode == LESS)
		ft_iteration(frct, keycode);
	/* else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW ||
				keycode == UP_ARROW || keycode == DOWN_ARROW)
		ft_move(keycode, fdf);
	else if (keycode == ONE_NUM_PAD || keycode == TWO_NUM_PAD)
		ft_zoom(keycode, fdf);
	else if (keycode == SEVEN_NUM_PAD || keycode == EIGHT_NUM_PAD)
		ft_elevation(keycode, fdf);
	else if (keycode == NINE_NUM_PAD || keycode == SIX_NUM_PAD)
		ft_rotate(keycode, fdf);
	else if (keycode == THREE_NUM_PAD)
		ft_switch_color(fdf);
	else if (keycode == ZERO_NUM_PAD)
		ft_switch_projection(fdf); */
	if (ft_print(frct) == -1)
		return (-1);
	return (0);
}
