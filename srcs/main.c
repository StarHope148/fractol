/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:53:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/01 17:13:51 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_error()
{
	ft_putendl_fd("an error occured", 2);
	return (EXIT_FAILURE);
}

int		ft_usage(void)
{
	ft_putendl_fd("usage: ./fdf [fractal]\n\n-> Sierpinski\n-> Mandelbrot\n-> Julia", 2);
	return (EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (ft_usage());
	if (ft_fractol(av[1]) == -1)
		return (-1);
	return (0);
}

