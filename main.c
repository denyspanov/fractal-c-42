/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:47:27 by dpanov            #+#    #+#             */
/*   Updated: 2017/04/05 13:52:08 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	standart_data(t_data **data)
{
	(*data)->scale = 1.0;
	(*data)->y_pos = 0.0;
	(*data)->r = 1;
	(*data)->g = 1;
	(*data)->b = 1;
	(*data)->jul = 1;
	(*data)->x_pos = 0.0;
	(*data)->threads = 1;
	(*data)->mouse_y = 1.0;
	(*data)->mouse_x = 1.0;
	(*data)->win_width = 600;
	(*data)->win_height = 600;
	(*data)->max = 30;
}

void	mlx_it(t_data **data)
{
	(*data)->mlx = mlx_init();
	(*data)->win = mlx_new_window((*data)->mlx, (*data)->win_width,
(*data)->win_height, "Fractal");
}

void	fractal_sss(char *s, t_data **data, int i)
{
	if (!ft_strcmp(s, "brain"))
	{
		i = 1;
		(*data)->fract = 4;
	}
	if (!ft_strcmp(s, "brain_1"))
	{
		i = 1;
		(*data)->fract = 5;
	}
	if (!ft_strcmp(s, "juliav"))
	{
		i = 1;
		(*data)->fract = 6;
	}
	if (i == 0)
		errors(2);
	else
	{
		standart_data(&(*data));
		mlx_it(&(*data));
	}
}

void	fractal_selection(char *s, t_data **data)
{
	int i;

	i = 0;
	if (!ft_strcmp(s, "mandelbrot"))
	{
		i = 1;
		(*data)->fract = 1;
	}
	else if (!ft_strcmp(s, "julia"))
	{
		i = 1;
		(*data)->fract = 2;
	}
	else if (!ft_strcmp(s, "burningship"))
	{
		i = 1;
		(*data)->fract = 3;
	}
	fractal_sss(s, &(*data), i);
}

int		main(int argc, char **argv)
{
	t_data *data;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		fractal_selection(argv[1], &data);
		mlx_mouse_hook(data->win, mouse_hook, &data);
		mlx_hook(data->win, MOT, POINT,
julia_trash, &data);
		mlx_hook(data->win, 2, 0, key_f, &data);
		mlx_hook(data->win, 17, 0, key_x, &data);
		mlx_loop_hook(data->mlx, &mult_thrd, &data);
		mlx_loop(data->mlx);
	}
	else
		errors(1);
	return (0);
}
