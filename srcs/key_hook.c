/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:09 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/30 14:21:51 by jcanteau         ###   ########.fr       */
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

int		ft_key_hook(int keycode, t_env *frct)
{
	if (keycode == ESC)
		ft_exit(frct);
	else if (keycode == MORE || keycode == LESS)
		ft_iteration(frct, keycode);
	if (ft_print(frct) == -1)
		return (-1);
	return (0);
}
