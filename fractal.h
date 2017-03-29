#ifndef FRACTAL_H
# define FRACTAL_H
# define MotionNotify 6
# define PointerMotionMask (1L<<6)
# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
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
	double			mouse_x;
	double mouse_y;
	double 		tmp;
	int			col;
	int 		row;
	int			win_width;
	int			win_height;
	int			fract;
}				t_data;
int ss(t_data **data);
#endif