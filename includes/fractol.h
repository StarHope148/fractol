/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:34:34 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/03 19:31:00 by jcanteau         ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 800

# define MOVE_SPEED 0.05
# define ZOOM_SPEED 1.06

/* # define XMIN -1.25
# define XMAX 1.25
# define YMIN -1.25
# define YMAX 1.25 */

typedef enum	e_color_mod
{
	BLUE_MOD,
	RED_MOD,
	GREEN_MOD
}				t_color_mod;

typedef enum	e_fractal_name
{
	SIERPINSKI,
	MANDELBROT,
	JULIA,
	BURNINGSHIP
}				t_fractal_name;

typedef struct 	s_complex
{
    double 		cx;
    double 		cy;
	double		xn;
	double		yn;
} 				t_complex;

typedef struct  s_point
{
    int     	x;
    int     	y;
}               t_point;

typedef struct	s_env
{
	t_point		mouse;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			width;
	int			height;
	int			bpp;
	int			size_l;
	int			endian;
	int			fractal;
	int			itermax;
	double		hor;
	double		vert;
	double		zoom;
	char		colormod;
	char		motion;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
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
int			ft_mouse_hook(int keycode, int x, int y, t_env *frct);
void		ft_iteration(t_env *frct, int keycode);
void		ft_mandelbrot(t_env *frct);
void		ft_burningship(t_env *frct);
void		ft_julia(t_env *frct);
void		ft_move(t_env *frct, int keycode);
void		ft_zoom(t_env *frct, int keycode);
void		ft_color(t_env *frct, int n, int x, int y);
void		ft_default(t_env *frct);
int			ft_mouse_motion(int x, int y, t_env *frct);


#endif