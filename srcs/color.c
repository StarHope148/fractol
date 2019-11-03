/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:59:26 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 15:59:56 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_rgb(int r, int g, int b)
{
	r *= 256 * 256;
	g *= 256;
	return (r + g + b);
}

void	ft_color(t_env *frct, int n, int x, int y)
{
	if (n == frct->itermax)
		frct->data[y * frct->width + x] = BLACK;
	else if (frct->colormod == BLUE_MOD)
		frct->data[y * frct->width + x] = ft_rgb(0, 0, n * 255 / frct->itermax);
	else if (frct->colormod == RED_MOD)
		frct->data[y * frct->width + x] = ft_rgb(n * 255 / frct->itermax, 0, 0);
	else if (frct->colormod == GREEN_MOD)
		frct->data[y * frct->width + x] = ft_rgb(0, n * 255 / frct->itermax, 0);
		/* else if (n > frct->itermax * 0.90)
			frct->data[y * frct->width + x] = DARK_BLUE;
		else if (n > frct->itermax * 0.70)
			frct->data[y * frct->width + x] = BLUE;
		else if (n > frct->itermax * 0.50)
			frct->data[y * frct->width + x] = CYAN;
		else
			frct->data[y * frct->width + x] = BLACK; */
}