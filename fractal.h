#ifndef FRACTAL_H
# define FRACTAL_H
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
	double		max;
	int			win_width;
	int			win_height;
}				t_data;
void			mlx_it(t_data **data);
#endif