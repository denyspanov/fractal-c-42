/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:30:59 by dpanov            #+#    #+#             */
/*   Updated: 2017/04/05 16:32:57 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	key_ffff(int keycode, t_data **data)
{
	if (keycode == SIX_K)
	{
		standart_data(&(*data));
		(*data)->fract = 6;
	}
}

void	key_fff(int keycode, t_data **data)
{
	if (keycode == R_K && (*data)->r > 0.1)
		(*data)->r -= 0.1;
	if (keycode == T_K && (*data)->r < 1)
		(*data)->r += 0.1;
	if (keycode == G_K && (*data)->g > 0.1)
		(*data)->g -= 0.1;
	if (keycode == H_K && (*data)->g < 1)
		(*data)->g += 0.1;
	if (keycode == B_K && (*data)->b > 0.1)
		(*data)->b -= 0.1;
	if (keycode == FOUR_K)
	{
		standart_data(&(*data));
		(*data)->fract = 4;
	}
	if (keycode == ONE_N && (*data)->threads > 1)
		(*data)->threads -= 1;
	if (keycode == TWO_N && (*data)->threads < 4)
		(*data)->threads += 1;
	if (keycode == FIVE_K)
	{
		standart_data(&(*data));
		(*data)->fract = 5;
	}
	key_ffff(keycode, &(*data));
}

void	key_ff(int keycode, t_data **data)
{
	if (keycode == N_K && (*data)->b < 1)
		(*data)->b += 0.1;
	if (keycode == MINUS_K && (*data)->max > 10)
		(*data)->max -= 10;
	if (keycode == ONE_K)
	{
		standart_data(&(*data));
		(*data)->fract = 1;
	}
	if (keycode == TWO_K)
	{
		standart_data(&(*data));
		(*data)->fract = 2;
	}
	if (keycode == THREE_K)
	{
		standart_data(&(*data));
		(*data)->fract = 3;
	}
	key_fff(keycode, &(*data));
}

int		key_f(int keycode, t_data **data)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT)
		(*data)->x_pos += 10 * (*data)->scale / 100;
	if (keycode == LEFT)
		(*data)->x_pos -= 10 * (*data)->scale / 100;
	if (keycode == DOWN)
		(*data)->y_pos += 10 * (*data)->scale / 100;
	if (keycode == UP)
		(*data)->y_pos -= 10 * (*data)->scale / 100;
	if (keycode == PLUS_N)
		(*data)->scale /= 1.25;
	if (keycode == MINUS_N && (*data)->scale < 1)
		(*data)->scale *= 1.25;
	if (keycode == PLUS_K)
		(*data)->max += 10;
	if (keycode == J_K)
	{
		if ((*data)->jul)
			(*data)->jul = 0;
		else
			(*data)->jul = 1;
	}
	key_ff(keycode, &(*data));
	return (0);
}

int		mouse_hook(int keycode, int x, int y, t_data **data)
{
	y -= (*data)->win_height / 2;
	x -= (*data)->win_width / 2;
	(*data)->x_pos += x * (*data)->scale / 150.0;
	(*data)->y_pos += y * (*data)->scale / 150.0;
	if (keycode == 4)
		(*data)->scale /= 1.25;
	else if (keycode == 5 && (*data)->scale < 1)
		(*data)->scale *= 1.25;
	(*data)->x_pos -= x * (*data)->scale / 150.0;
	(*data)->y_pos -= y * (*data)->scale / 150.0;
	return (0);
}
