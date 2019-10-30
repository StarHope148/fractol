/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:34:34 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 20:36:52 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>				//DEBUG
# include "../libft/libft.h"
# include "keys.h"
# include "colors.h"

typedef enum	e_fractal
{
	NONE,
	SIERPINSKI,
	MANDELBROT,
	JULIA
}				t_fractal;

typedef struct  s_point
{
    int     x;
    int     y;
}               t_point;

typedef struct	s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;
	int				width;
	int				height;
	int				bpp;
	int				size_l;
	int				endian;
	int				fractal;
	int				iter;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}				t_env;

int			ft_fractol(char *filename);
int			ft_mlx(t_env *frct);
void        ft_sierpinski(t_env *frct, t_point p0, t_point p1, t_point p2, int limit);
int			ft_print(t_env *frct);
void    	ft_draw_triangle(t_env *frct, t_point A, t_point B, t_point C);
void		bresenham(t_env *frct, t_point A, t_point B);
int			ft_link_points(t_env *frct);
int			ft_usage(void);
int			ft_key_hook(int keycode, t_env *frct);
int			ft_mouse_hook(int keycode, t_env *frct);
void		ft_iteration(t_env *frct, int keycode);

#endif