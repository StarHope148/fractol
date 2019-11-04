/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:34:34 by jcanteau          #+#    #+#             */
/*   Updated: 2019/11/04 18:45:54 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "keys.h"
# include "colors.h"

# define WIDTH 1000
# define HEIGHT 800

# define MOVE_SPEED 0.05
# define ZOOM_SPEED 1.06
# define MOUSE_S 0.005

typedef enum	e_color_mod
{
	BLUE_MOD,
	RED_MOD,
	GREEN_MOD,
	RAND_MOD
}				t_color_mod;

typedef enum	e_fractal_name
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
	MULTIBROT,
	TRICORN
}				t_fractal_name;

typedef struct	s_complex
{
	double		cx;
	double		cy;
	double		xn;
	double		yn;
}				t_complex;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

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
	int			n;
}				t_env;

int				ft_fractol(char *filename);
int				ft_mlx(t_env *frct);
int				ft_print(t_env *frct);
int				ft_draw(t_env *frct);
int				ft_usage(void);
int				ft_key_hook(int keycode, t_env *frct);
int				ft_mouse_hook(int keycode, int x, int y, t_env *frct);
void			ft_iteration(t_env *frct, int keycode);
void			ft_mandelbrot(t_env *frct);
void			ft_burningship(t_env *frct);
void			ft_julia(t_env *frct);
void			ft_mandelbrot_duo(t_env *frct);
void			ft_tricorn(t_env *frct);
void			ft_move(t_env *frct, int keycode);
void			ft_zoom(t_env *frct, int keycode);
void			ft_color(t_env *frct, int n, int x, int y);
void			ft_default(t_env *frct);
int				ft_mouse_motion(int x, int y, t_env *frct);
void			ft_init_fractal(t_env *frct);
void			ft_switch_color(t_env *frct);
void			ft_switch_fractal(t_env *frct);
void			ft_exit(t_env *frct);
void			ft_zoom_mouse(int mousekey, int x, int y, t_env *frct);
void			ft_show_fractal_name(t_env *frct);

#endif
