/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:34:30 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 15:35:57 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void         ft_sierpinski(t_env *frct, t_point p0, t_point p1, t_point p2, int limit)
{
    t_point     pA;
    t_point     pB;
    t_point     pC;

    if (limit > 0)
    {
        pA.x = (p0.x + p1.x) / 2;
        pA.y = (p0.y + p1.y) / 2;
        pB.x = (p1.x + p2.x) / 2;
        pB.y = (p1.y + p2.y) / 2;
        pC.x = (p2.x + p0.x) / 2;
        pC.y = (p2.y + p0.y) / 2;
        ft_sierpinski(frct, p0, pA, pC, limit -1);
        ft_sierpinski(frct, pA, p1, pB, limit -1);
        ft_sierpinski(frct, pC, pB, p2, limit -1);
    }
    else
    {
        ft_draw_triangle(frct, p0, p1, p2);
    }
}