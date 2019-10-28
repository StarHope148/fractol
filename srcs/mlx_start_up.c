/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:10:29 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/28 16:08:06 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_mlx(t_env *frct)
{
	if ((frct->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	frct->win_ptr = mlx_new_window(frct->mlx_ptr, frct->width,
									frct->height, "FRACTOL");
	if (frct->win_ptr == NULL)
		return (-1);
	/* if (ft_print(fdf) == -1)
		return (-1); */
	//mlx_hook(fdf->win_ptr, 2, 0, ft_key_hook, fdf);
	mlx_loop(frct->mlx_ptr);
	return (0);
}
