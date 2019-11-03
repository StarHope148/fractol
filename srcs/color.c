/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 15:59:26 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 21:06:04 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_rgb(int r, int g, int b)
{
	r *= 256 * 256;
	g *= 256;
	return (r + g + b);
}

void	ft_rand_color(t_env *frct, int n, int x, int y)
{
	if (n == frct->itermax)
		frct->data[y * frct->width + x] = BLACK;
	else if (n > frct->itermax * 0.90)
		frct->data[y * frct->width + x] = DARK_BLUE;
	else if (n > frct->itermax * 0.70)
		frct->data[y * frct->width + x] = BLUE;
	else if (n > frct->itermax * 0.50)
		frct->data[y * frct->width + x] = CYAN;
	else if (n > frct->itermax * 0.30)
		frct->data[y * frct->width + x] = TEAL;
	else if (n > frct->itermax * 0.10)
		frct->data[y * frct->width + x] = SAND;
	else if (n > frct->itermax * 0.075)
		frct->data[y * frct->width + x] = PURPLE;
	else if (n > frct->itermax * 0.05)
		frct->data[y * frct->width + x] = RED;
	else
		frct->data[y * frct->width + x] = WHITE;
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
	else if (frct->colormod == RAND_MOD)
		ft_rand_color(frct, n, x, y);
}
