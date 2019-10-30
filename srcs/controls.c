/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:25:14 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 20:32:41 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_iteration(t_env *frct, int keycode)
{
	if (keycode == MORE)
		frct->iter++;
	else if (frct->iter > 0)
		frct->iter--;
	printf("iteration : %d\n", frct->iter);					//DEBUG
}