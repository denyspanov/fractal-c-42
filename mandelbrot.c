#include "fractal.h"

void    mandelbrot(t_data **data)
{
	ft_create_image(&(*data), 1);
	(*data)->row = -1;
	while (++(*data)->row < (*data)->win_height)
	{
		(*data)->col = -1;
		while (++(*data)->col < (*data)->win_width)
		{
			(*data)->c_re = ((*data)->col - (*data)->win_width / 2.0) * 4.0 / (*data)->win_width;
			(*data)->c_im = ((*data)->row - (*data)->win_height / 2.0) * 4.0 / (*data)->win_width;
			(*data)->c_re = (*data)->c_re / (*data)->scale + (*data)->x_pos;
			(*data)->c_im = (*data)->c_im / (*data)->scale + (*data)->y_pos;
			(*data)->x = 0;
			(*data)->y = 0;
			(*data)->iteration = -1;
			while ((*data)->x * (*data)->x + (*data)->y * (*data)->y < 4 && ++(*data)->iteration < (*data)->max)
			{
				(*data)->tmp = (*data)->x *(*data)-> x - (*data)->y * (*data)->y + (*data)->c_re;
				(*data)->y = 2 * (*data)->x * (*data)->y + (*data)->c_im;
				(*data)->x = (*data)->tmp;
			}
			if ((*data)->iteration < (*data)->max)
				ft_put_px(&(*data), (*data)->col, (*data)->row, (*data)->iteration * 2);
			else
				ft_put_px(&(*data), (*data)->col, (*data)->row, 0);
		}
	}
	ft_create_image(&(*data), 2);
}