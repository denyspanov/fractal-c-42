#ifndef FRACTAL_H
# define FRACTAL_H
#ifdef __linux
 # define LEFT 65361
 # define RIGHT 65363
 # define UP 65362
 # define DOWN 65364
 # define ESC 65307
 # define PLUS_N 65451
 # define MINUS_N 65453
 # define PLUS_K 61
 # define MINUS_K 45
# else
 # define LEFT 123
 # define RIGHT 124
 # define UP 126
 # define DOWN 125
 # define ESC 53
 # define PLUS_N 69
 # define MINUS_N 78
 # define PLUS_K 61
 # define MINUS_K 45
# endif
# define NUM_THREADS 4
# define MotionNotify 6
# define PointerMotionMask (1L<<6)
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
	double		c_re;
	double 		c_im;
	double		max;
	int			iteration;
	double		x;
	double 		y;
	double		mouse_x;
	double		mouse_y;
	double 		tmp;
	int			win_width;
	int			win_height;
	int			fract;
}				t_data;
typedef struct s_thread_data {
	int			tid;
	int			x_start;
	int			y_start;
	int			x_end;
	int	y_end;
	t_data *data;
} t_thread_data;

typedef struct s_fractal {
	double c_re;
	double c_im;
	double iteration;
	double x;
	double y;
	int s;
	double tmp;
}t_fractal;

int		selector(t_data **data);
int		key_f(int keycode, t_data **data);
void    burningship(t_data *data, int x_start, int x_end, int y_start);
int		mouse_hook(int x, int y, t_data **data);
void    mandelbrot(t_data *data, int x, int x1, int y);
void	ft_put_px(t_data *data, int x, int y, double color);
void	ft_create_image(t_data **data, int n);
int		mult_thrd(t_data **data);
#endif