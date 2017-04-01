
#include "fractal.h"

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

int selector(t_data **data)
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
		mlx_loop_hook(data->mlx, &selector, &data);
		mlx_loop(data->mlx);
    }
    else
		ft_putstr("Usage: ./fractal [fractal]\nSelect: Mandelbrot, Julia, BurningShip.\n");
    return (0);
}