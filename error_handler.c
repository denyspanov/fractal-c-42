/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:04:45 by dpanov            #+#    #+#             */
/*   Updated: 2017/04/05 18:09:32 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	errors(int i)
{
	if (i == 1)
	{
		ft_putstr("Usage: ./fractal [fractal]\n");
		ft_putstr("Select: mandelbrot, julia, burningship, brain, brain_1, ");
		ft_putstr("juliav.\n");
	}
	if (i == 2)
	{
		ft_putstr("Fractals available: mandelbrot, julia, burningship,");
		ft_putstr(" brain, brain_1, juliav.\n");
	}
	exit(0);
}

int		julia_trash(int x, int y, t_data **data)
{
	if (x > -1 && x < (*data)->win_width && y > -1 && y <
			(*data)->win_height && (*data)->jul == 1)
	{
		(*data)->mouse_x = x / ((*data)->win_width / 2.5);
		(*data)->mouse_y = y / ((*data)->win_height / 2.5);
	}
	return (0);
}
