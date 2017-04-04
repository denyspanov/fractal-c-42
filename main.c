
#include "fractal.h"

void	standart_data(t_data **data, char *s)
{
	(*data)->scale = 0.8;
	(*data)->y_pos = 0;
	(*data)->fract = 1;
	(*data)->x_pos = 0;
    (*data)->threads = 1;
	(*data)->mouse_y = 1;
	(*data)->mouse_x = 1;
	(*data)->win_width = 600;
	(*data)->win_height = 600;
	(*data)->max = 30;
	(*data)->mlx = mlx_init();
	(*data)->win = mlx_new_window((*data)->mlx,(*data)->win_width,(*data)->win_height, s);
}

void	fractal_selection(char *s, t_data **data)
{
	if (!ft_strcmp(s, "mandelbrot"))
	{
		standart_data(&(*data), "Fractal: Mandelbrot.");
		(*data)->fract = 1;
	}
	else if (!ft_strcmp(s, "julia"))
	{
		standart_data(&(*data), "Fractal: Julia.");
		(*data)->fract = 2;
	}
	else if (!ft_strcmp(s, "burningship"))
	{
		standart_data(&(*data), "Fractal: BurningShip.");
		(*data)->fract = 3;
	}
	else
		errors(2);
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
		mlx_loop_hook(data->mlx, &mult_thrd, &data);
		mlx_loop(data->mlx);
    }
    else
		errors(1);
    return (0);
}