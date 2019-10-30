/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:53:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 20:33:48 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
/* 
**	BETTER WATCH FOR LEAKS
*/
//__attribute__((destructor)) void no_end(void);

int		ft_error(int error)
{
	ft_putendl_fd("an error occured", 2);
	return (EXIT_FAILURE);
}

int		ft_usage(void)
{
	ft_putendl_fd("usage: ./fdf [fractal]\n\n\t\tSierpinski\n\t\tMandelbrot\n\t\tJulia", 2);
	return (EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (ft_usage());
	if (ft_strcmp(av[1], "/dev/zero") == 0)
		return (ft_error(-5));
	if (ft_fractol(av[1]) == -1)
		return (-1);
	/* if ((error = ft_check_file(av[1])) < 0)
		return (ft_error(error));
	if ((error = ft_fdf_init(av[1])) == -1)
		return (ft_error(error)); */
	return (0);
}

/*  void	no_end(void)
{
	while (1);
} */
