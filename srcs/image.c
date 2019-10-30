/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 19:27:54 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_print(t_env *frct)
{
	if (frct->img_ptr == NULL)
	{
		frct->img_ptr = mlx_new_image(frct->mlx_ptr, frct->width, frct->height);
		if (frct->img_ptr == NULL)
			return (-1);
		frct->data = (int *)mlx_get_data_addr(frct->img_ptr, &frct->bpp,
												&frct->size_l, &frct->endian);
		if (frct->data == NULL)
			return (-1);
	}
	ft_bzero(frct->data, frct->width * frct->height * 4);
 	if (ft_link_points(frct) == -1)
		return (-1);
	mlx_put_image_to_window(frct->mlx_ptr, frct->win_ptr, frct->img_ptr, 0, 0);
	/* if (ft_print_menu(frct) == -1)
		return (-1);
	ft_print_color_setup(frct); */
	return (0);
}

/* void	ft_link_right(t_env *frct, int r, int c)
{
	frct->pix.xcur = frct->pro[r][c].px;
	frct->pix.ycur = frct->pro[r][c].py;
	frct->pix.xnext = frct->pro[r][c + 1].px;
	frct->pix.ynext = frct->pro[r][c + 1].py;
	bresenham(frct, frct->map.tab[r][c].color);
}

void	ft_link_down(t_env *frct, int r, int c)
{
	frct->pix.xcur = frct->pro[r][c].px;
	frct->pix.ycur = frct->pro[r][c].py;
	frct->pix.xnext = frct->pro[r + 1][c].px;
	frct->pix.ynext = frct->pro[r + 1][c].py;
	bresenham(frct, frct->map.tab[r][c].color);
} */

int		ft_link_points(t_env *frct)
{
	t_point pA;
	t_point pB;
	t_point pC;

	pA.x = 0;
	pA.y = 800;
	pB.x = 1000;
	pB.y = 800;
	pC.x = 500;
	pC.y = 200;
	if (frct->fractal == SIERPINSKI)
		ft_sierpinski(frct, pA, pB, pC, frct->iter);
	return (0);
}
