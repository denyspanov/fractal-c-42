/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:26:15 by dpanov            #+#    #+#             */
/*   Updated: 2017/04/05 14:35:30 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	norm_helper_man(t_fractal *fract, t_data *data, int y_start)
{
	fract->c_re = (fract->s - data->win_width / 2.0) * 4.0 / data->win_width;
	fract->c_im = (y_start - data->win_height / 2.0) * 4.0 / data->win_width;
	fract->c_re = fract->c_re * data->scale + data->x_pos;
	fract->c_im = fract->c_im * data->scale + data->y_pos;
	fract->x = 0;
	fract->y = 0;
	fract->iteration = -1;
}

void	mandelbrot(t_data *data, int x_start, int x_end, int y_start)
{
	t_fractal *fract;

	fract = (t_fractal *)malloc(sizeof(t_fractal));
	while (++y_start - 1 < data->win_height)
	{
		fract->s = x_start - 1;
		while (++fract->s < x_end)
		{
			norm_helper_man(fract, data, y_start);
			while (fract->x * fract->x + fract->y *
fract->y < 4 && ++fract->iteration < data->max)
			{
				fract->tmp = (fract->x * fract->x - fract->y *
fract->y + fract->c_re);
				fract->y = 2 * fract->x * fract->y + fract->c_im;
				fract->x = fract->tmp;
			}
			if (fract->iteration < data->max)
				ft_put_px(data, fract->s, y_start, fract->iteration);
			else
				ft_put_px(data, fract->s, y_start, 0);
		}
	}
}
