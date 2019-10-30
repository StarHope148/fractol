/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:48:37 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 17:31:33 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    ft_draw_triangle(t_env *frct, t_point A, t_point B, t_point C)
{
    bresenham(frct, A, B);
    bresenham(frct, B, C);
    bresenham(frct, C, A);
}