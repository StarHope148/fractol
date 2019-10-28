/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:48:37 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/28 16:54:18 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    ft_draw_triangle(t_point A, t_point B, t_point C)
{
    t_point cur;
    t_point next;

    cur = A;
    next = B;
    bresenham(frct, A, B);
    cur = B;
    next = C;
    bresenham(frct, B, A);
    cur = C;
    next = A;
    bresenham(frct, C, A);

}