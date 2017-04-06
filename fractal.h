/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:11:25 by dpanov            #+#    #+#             */
/*   Updated: 2017/04/05 17:13:04 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ESC 53
# define PLUS_N 69
# define MINUS_N 78
# define PLUS_K 24
# define MINUS_K 27
# define ONE_N 83
# define TWO_N 84
# define R_K 15
# define T_K 17
# define G_K 5
# define H_K 4
# define B_K 11
# define N_K 45
# define ONE_K 18
# define TWO_K 19
# define THREE_K 20
# define FOUR_K 21
# define FIVE_K 23
# define SIX_K 22
# define J_K 38
# define MOT 6
# define POINT (1L<<6)
# include "mlx.h"
# include <pthread.h>
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	double		scale;
	double		x_pos;
	double		y_pos;
	double		max;
	double		r;
	double		g;
	double		b;
	double		mouse_x;
	double		mouse_y;
	double		tmp;
	int			win_width;
	int			win_height;
	int			fract;
	int			threads;
	int			jul;
}				t_data;
typedef struct	s_thread_data
{
	int			tid;
	int			x_start;
	int			y_start;
	int			x_end;
	int			y_end;
	t_data		*data;
}				t_thread_data;
typedef struct	s_fractal
{
	double		c_re;
	double		c_im;
	double		n_c_re;
	double		n_c_im;
	double		o_c_re;
	double		o_c_im;
	double		iteration;
	double		x;
	double		y;
	int			s;
	double		tmp;
}				t_fractal;
void			brain(t_data *data, int x_start, int x_end, int y_start);
int				key_f(int keycode, t_data **data);
int				julia_trash(int x, int y, t_data **data);
int				mouse_hook(int keycode, int x, int y, t_data **data);
void			ft_put_menu(t_data **data);
void			mandelbrot(t_data *data, int x_start, int x_end, int y_start);
void			ft_put_px(t_data *data, int x, int y, double color);
int				key_x(t_data **data);
void			errors(int i);
void			standart_data(t_data **data);
void			*thr_func(void *arg);
void			julia(t_data *data, int x_start, int x_end, int y_start);
int				mult_thrd(t_data **data);
void			ft_create_image(t_data **data, int n);
void			burningship(t_data *data, int x_start, int x_end, int y_start);
void			brain_v(t_data *data, int x_start, int x_end, int y_start);
void			juliav(t_data *data, int x_start, int x_end, int y_start);
#endif
