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
# ifdef __linux
# define KEY_ESCAPE         65307
# define KEY_F1             65470
# define KEY_F2             65471
# define KEY_F3             65472
# define KEY_F4             65473
# define KEY_F5             65474
# define KEY_F6             65475
# define KEY_F7             65476
# define KEY_F8             65477
# define KEY_F9             65478
# define KEY_F10            65479
# define KEY_F11            65480
# define KEY_F12            65481
# define KEY_SCROLL_LOCK    65300
# define KEY_PAUSE          65299
# define KEY_TILDE          96
# define KEY_1              49
# define KEY_2              50
# define KEY_3              51
# define KEY_4              52
# define KEY_5              53
# define KEY_6              54
# define KEY_7              55
# define KEY_8              56
# define KEY_9              57
# define KEY_0              48
# define KEY_MINUS          45
# define KEY_UNDERSCORE     45
# define KEY_EQUAL          61
# define KEY_BACKSPACE      65288
# define KEY_TAB            65289
# define KEY_Q              113
# define KEY_W              119
# define KEY_E              101
# define KEY_R              114
# define KEY_T              116
# define KEY_Y              121
# define KEY_U              117
# define KEY_I              105
# define KEY_O              111
# define KEY_P              112
# define KEY_OPEN_BRACKET   91
# define KEY_OPEN_BRACE     91
# define KEY_CLOSE_BRACKET  93
# define KEY_CLOSE_BRACE    93
# define KEY_BACKSLASH      92
# define KEY_PIPE           92
# define KEY_CAPSLOCK       65509
# define KEY_A              97
# define KEY_S              115
# define KEY_D              100
# define KEY_F              102
# define KEY_G              103
# define KEY_H              104
# define KEY_J              106
# define KEY_K              107
# define KEY_L              108
# define KEY_COLON          52
# define KEY_SEMI_COLON     52
# define KEY_SIMPLE_QUOTE   39
# define KEY_DOUBLE_QUOTES  39
# define KEY_ENTER          65293
# define KEY_SHIFT_LEFT     65505
# define KEY_Z              122
# define KEY_X              120
# define KEY_C              99
# define KEY_V              118
# define KEY_B              98
# define KEY_N              110
# define KEY_M              109
# define KEY_LESS_THAN      44
# define KEY_COMMA          44
# define KEY_GREATER_THAN   46
# define KEY_DOT            46
# define KEY_SLASH          47
# define KEY_QUESTION_MARK  47
# define KEY_SHIFT_RIGHT    65506
# define KEY_CTRL_LEFT      65507
# define KEY_ALT            65513
# define KEY_SPACEBAR       32
# define KEY_ALT_GR         65514
# define KEY_MENU           65383
# define KEY_CTRL_RIGHT     65508
# define KEY_LEFT           65361
# define KEY_DOWN           65364
# define KEY_RIGHT          65363
# define KEY_UP             65362
# define KEY_INSERT         65379
# define KEY_DEL            65535
# define KEY_HOME           65360
# define KEY_END            65367
# define KEY_PAGE_UP        65365
# define KEY_PAGE_DOWN      65366
# define KEY_NUM_LOCK       65407
# define KEY_PAD_1          65436
# define KEY_PAD_2          65433
# define KEY_PAD_3          65435
# define KEY_PAD_4          65430
# define KEY_PAD_5          65437
# define KEY_PAD_6          65432
# define KEY_PAD_7          65429
# define KEY_PAD_8          65431
# define KEY_PAD_9          65434
# define KEY_PAD_0          65438
# define KEY_PAD_DIVIDE     65455
# define KEY_PAD_MULTIPLY   65450
# define KEY_PAD_SUB        65453
# define KEY_PAD_ADD        65451
# define KEY_PAD_ENTER      65421
# define KEY_PAD_DOT        65439
# define KEY_PAD_DELETE     65439
# else
# define KEY_ESCAPE         53
# define KEY_F1             122
# define KEY_F2             120
# define KEY_F3             99
# define KEY_F4             118
# define KEY_F5             96
# define KEY_F6             97
# define KEY_F7             98
# define KEY_F8             100
# define KEY_F9             101
# define KEY_F10            109
# define KEY_F11            103
# define KEY_F12            111
# define KEY_F13            105
# define KEY_F14            107
# define KEY_F15            113
# define KEY_F16            106
# define KEY_F17            64
# define KEY_F18            79
# define KEY_F19            80
# define KEY_TILDE          50
# define KEY_1              18
# define KEY_2              19
# define KEY_3              20
# define KEY_4              21
# define KEY_5              23
# define KEY_6              22
# define KEY_7              26
# define KEY_8              28
# define KEY_9              25
# define KEY_0              29
# define KEY_MINUS          27
# define KEY_EQUAL          24
# define KEY_BACKSPACE      51
# define KEY_TAB            48
# define KEY_Q              12
# define KEY_W              13
# define KEY_E              14
# define KEY_R              15
# define KEY_T              17
# define KEY_Y              16
# define KEY_U              32
# define KEY_I              34
# define KEY_O              31
# define KEY_P              35
# define KEY_OPEN_BRACKET   33
# define KEY_OPEN_BRACE     33
# define KEY_CLOSE_BRACKET  30
# define KEY_CLOSE_BRACE    30
# define KEY_BACKSLASH      42
# define KEY_PIPE           42
# define KEY_CAPSLOCK       272
# define KEY_A              0
# define KEY_S              1
# define KEY_D              2
# define KEY_F              3
# define KEY_G              5
# define KEY_H              4
# define KEY_J              38
# define KEY_K              40
# define KEY_L              37
# define KEY_COLON          41
# define KEY_SEMI_COLON     41
# define KEY_SIMPLE_QUOTE   39
# define KEY_DOUBLE_QUOTES  39
# define KEY_ENTER          36
# define KEY_SHIFT_LEFT     257
# define KEY_Z              6
# define KEY_X              7
# define KEY_C              8
# define KEY_V              9
# define KEY_B              11
# define KEY_N              45
# define KEY_M              46
# define KEY_LESS_THAN      43
# define KEY_COMMA          43
# define KEY_GREATER_THAN   47
# define KEY_DOT            47
# define KEY_SLASH          44
# define KEY_QUESTION_MARK  44
# define KEY_SHIFT_RIGHT    258
# define KEY_CTRL_LEFT      256
# define KEY_COMMAND_LEFT   259
# define KEY_OPTION_LEFT    261
# define KEY_ALT            261
# define KEY_SPACEBAR       49
# define KEY_COMMAND_RIGHT  260
# define KEY_ALT_GR         262
# define KEY_FN             279
# define KEY_CTRL_RIGHT     269
# define KEY_LEFT           123
# define KEY_DOWN           125
# define KEY_RIGHT          124
# define KEY_UP             126
# define KEY_DEL            117
# define KEY_HOME           115
# define KEY_END            119
# define KEY_PAGE_UP        116
# define KEY_PAGE_DOWN      121
# define KEY_CLEAR          71
# define KEY_PAD_1          83
# define KEY_PAD_2          84
# define KEY_PAD_3          85
# define KEY_PAD_4          86
# define KEY_PAD_5          87
# define KEY_PAD_6          88
# define KEY_PAD_7          89
# define KEY_PAD_8          91
# define KEY_PAD_9          92
# define KEY_PAD_0          82
# define KEY_PAD_EQUAL      81
# define KEY_PAD_DIVIDE     75
# define KEY_PAD_MULTIPLY   67
# define KEY_PAD_SUB        78
# define KEY_PAD_ADD        69
# define KEY_PAD_ENTER      76
# define KEY_PAD_DOT        65
# endif
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
