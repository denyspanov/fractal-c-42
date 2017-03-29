
#include "fractal.h"
#include <stdio.h>

void	ft_put_px(t_data **data, int x, int y, double color)
{
	int p;

	p = (x * 4) + (y * 5120);
	if (p >= 0 && p < (3686400) && x < 1280 && y < 720 && x > 0)
	{
		(*data)->data[p] = 20 * color;
		(*data)->data[p + 1] = 3 * color;
		(*data)->data[p + 2] = 2 * color;
	}
}

void	ft_create_image(t_data **data, int n)
{
	int		sizeline;
	int		endian;
	int		bpp;

	if (n == 1)
	{
		(*data)->img = mlx_new_image((*data)->mlx,1280, 720);
		(*data)->data = mlx_get_data_addr((*data)->img,
										  &bpp, &sizeline, &endian);
	}
	if (n == 2)
	{
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img, 0, 0);
		mlx_destroy_image((*data)->mlx, (*data)->img);
	}
}

void burning_ship(t_data **data)
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
			(*data)->c_re = (*data)->c_re / (*data)->scale + (*data)->x_pos / (*data)->mouse_x;
			(*data)->c_im = (*data)->c_im / (*data)->scale + (*data)->y_pos / (*data)->mouse_x;
			(*data)->x = 0;
			(*data)->y = 0;
			(*data)->iteration = -1;
			while ((*data)->x * (*data)->x + (*data)->y * (*data)->y < 4 && ++(*data)->iteration < (*data)->max)
			{
				(*data)->tmp = (*data)->y;
				(*data)->y = fabs(((*data)->x * (*data)->y + (*data)->x * (*data)->y + (*data)->c_im));
				(*data)->x = fabs(((*data)->x * (*data)->x - (*data)->tmp * (*data)->tmp + (*data)->c_re));
			}
			if ((*data)->iteration < (*data)->max)
				ft_put_px(&(*data), (*data)->col, (*data)->row, (*data)->iteration * 2);
			else
				ft_put_px(&(*data), (*data)->col, (*data)->row, 0);
		}
	}
	ft_create_image(&(*data), 2);
}

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
			(*data)->c_im /= (*data)->mouse_x;
			(*data)->c_re /= (*data)->mouse_y;
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

int		key_f(int keycode, t_data **data)
{
    if (keycode == 53)
        exit(0);
	if (keycode == 124)
		(*data)->x_pos += 0.1 / (*data)->scale;
	if (keycode == 123)
		(*data)->x_pos -= 0.1 / (*data)->scale;
	if (keycode == 125)
		(*data)->y_pos += 0.1 / (*data)->scale;
	if (keycode == 126)
		(*data)->y_pos -= 0.1/ (*data)->scale;
	if (keycode == 69)
		(*data)->scale += 0.5;
	if (keycode == 78)
		(*data)->scale -= 0.5;
    if (keycode == 24)
        (*data)->max += 10;
    if (keycode == 25)
        (*data)->max -= 10;
	return (0);
}

void	standart_data(t_data **data, char *s)
{
	(*data)->scale = 0.2;
	(*data)->y_pos = 0;
	(*data)->fract = 1;
	(*data)->x_pos = 0;
	(*data)->row = -1;
	(*data)->mouse_y = 1;
	(*data)->mouse_x = 1;
	(*data)->win_width = 1280;
	(*data)->win_height = 720;
	(*data)->max = 100;
	(*data)->mlx = mlx_init();
	(*data)->win = mlx_new_window((*data)->mlx,(*data)->win_width,(*data)->win_height, s);
}

void	fractal_selection(char *s, t_data **data)
{
	if (!ft_strcmp(s, "Mandelbrot"))
	{
		standart_data(&(*data), "Fractal: Mandelbrot.");
		(*data)->fract = 1;
	}
	if (!ft_strcmp(s, "Julia"))
	{
		standart_data(&(*data), "Fractal: Julia.");
		(*data)->fract = 2;
	}
	if (!ft_strcmp(s, "BurningShip"))
	{
		standart_data(&(*data), "Fractal: BurningShip.");
		(*data)->fract = 3;
	}
}

int		mouse_hook(int x, int y, t_data **data)
{
	if (x > -1 && x < 1281 && y > -1 && y < 721) {
		(*data)->mouse_y = y / 720;
		printf("%d\n", y);
		(*data)->mouse_x = x / 1280;
	}
}

int ss(t_data **data)
{
	if ((*data)->fract == 1)
		mandelbrot(&(*data));
	if ((*data)->fract == 3)
		burning_ship(&(*data));
	return (0);
}

int     main(int argc, char **argv)
{
	t_data *data;

    if (argc == 2)
	{
        data = (t_data *) malloc(sizeof(t_data));
		fractal_selection(argv[1], &data);
		mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_hook, &data);
		mlx_hook(data->win, 2, 3, key_f, &data);
		mlx_loop_hook(data->mlx, &ss, &data);
		mlx_loop(data->mlx);
    }
    else
		ft_putstr("Usage: ./fractal [fractal]\nSelect: Mandelbrot, Julia, BurningShip.\n");
    return (0);
}