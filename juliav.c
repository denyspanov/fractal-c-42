/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliav.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:08:45 by dpanov            #+#    #+#             */
/*   Updated: 2017/04/05 18:09:19 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	norm_helper_julv(t_fractal *fract, t_data *data, int y_start)
{
	fract->c_re = -0.7 * data->mouse_x;
	fract->c_im = 0.27015 * data->mouse_y;
	fract->n_c_re = 1.5 * (fract->s - data->win_width / 2) /
					(0.5 * data->win_width);
	fract->n_c_im = (y_start - data->win_height / 2) / (0.5 * data->win_height);
	fract->n_c_re = fract->n_c_re * data->scale + data->x_pos;
	fract->n_c_im = fract->n_c_im * data->scale + data->y_pos;
	fract->x = 0;
	fract->y = 0;
	fract->iteration = -1;
}

void	julian(t_fractal *fract)
{
	fract->o_c_re = fract->n_c_re;
	fract->o_c_im = fract->n_c_im;
	fract->n_c_re = (fract->o_c_re * fract->o_c_re -
		fract->o_c_im * fract->o_c_im + fract->c_re) *
			(fract->o_c_re * fract->o_c_re -
		fract->o_c_im * fract->o_c_im + fract->c_re);
	fract->n_c_im = (2 * fract->o_c_re *
		fract->o_c_im + fract->c_im) * (2 * fract->o_c_re *
										fract->o_c_im + fract->c_im);
}

void	juliav(t_data *data, int x_start, int x_end, int y_start)
{
	t_fractal *fract;

	fract = (t_fractal *)malloc(sizeof(t_fractal));
	while (++y_start - 1 < data->win_height)
	{
		fract->s = x_start - 1;
		while (++fract->s < x_end)
		{
			norm_helper_julv(fract, data, y_start);
			while (fract->n_c_re * fract->n_c_re + fract->n_c_im *
				fract->n_c_im < 4 && ++fract->iteration < data->max)
			{
				julian(fract);
			}
			if (fract->iteration < data->max)
				ft_put_px(data, fract->s, y_start, fract->iteration);
			else
				ft_put_px(data, fract->s, y_start, 0);
		}
	}
}
