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
	if (keycode == KEY_6)
	{
		standart_data(&(*data));
		(*data)->fract = 6;
	}
}

void	key_fff(int keycode, t_data **data)
{
	if (keycode == KEY_R && (*data)->r > 0.1)
		(*data)->r -= 0.1;
	if (keycode == KEY_T && (*data)->r < 1)
		(*data)->r += 0.1;
	if (keycode == KEY_G && (*data)->g > 0.1)
		(*data)->g -= 0.1;
	if (keycode == KEY_H && (*data)->g < 1)
		(*data)->g += 0.1;
	if (keycode == KEY_B && (*data)->b > 0.1)
		(*data)->b -= 0.1;
	if (keycode == KEY_4)
	{
		standart_data(&(*data));
		(*data)->fract = 4;
	}
	if (keycode == KEY_PAD_1 && (*data)->threads > 1)
		(*data)->threads -= 1;
	if (keycode == KEY_PAD_2 && (*data)->threads < 4)
		(*data)->threads += 1;
	if (keycode == KEY_5)
	{
		standart_data(&(*data));
		(*data)->fract = 5;
	}
	key_ffff(keycode, &(*data));
}

void	key_ff(int keycode, t_data **data)
{
	if (keycode == KEY_N && (*data)->b < 1)
		(*data)->b += 0.1;
	if (keycode == KEY_MINUS && (*data)->max > 10)
		(*data)->max -= 10;
	if (keycode == KEY_1)
	{
		standart_data(&(*data));
		(*data)->fract = 1;
	}
	if (keycode == KEY_2)
	{
		standart_data(&(*data));
		(*data)->fract = 2;
	}
	if (keycode == KEY_3)
	{
		standart_data(&(*data));
		(*data)->fract = 3;
	}
	key_fff(keycode, &(*data));
}

int		key_f(int keycode, t_data **data)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	if (keycode == KEY_RIGHT)
		(*data)->x_pos += 10 * (*data)->scale / 100;
	if (keycode == KEY_LEFT)
		(*data)->x_pos -= 10 * (*data)->scale / 100;
	if (keycode == KEY_DOWN)
		(*data)->y_pos += 10 * (*data)->scale / 100;
	if (keycode == KEY_UP)
		(*data)->y_pos -= 10 * (*data)->scale / 100;
	if (keycode == KEY_PAD_ADD)
		(*data)->scale /= 1.25;
	if (keycode == KEY_PAD_SUB && (*data)->scale < 1)
		(*data)->scale *= 1.25;
	if (keycode == KEY_EQUAL)
		(*data)->max += 10;
	if (keycode == KEY_J)
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
