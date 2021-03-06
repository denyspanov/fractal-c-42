/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:10:02 by dpanov            #+#    #+#             */
/*   Updated: 2017/04/05 17:45:00 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_put_px(t_data *data, int x, int y, double color)
{
	int p;

	p = (x * 4) + (y * data->win_width * 4);
	if ((p >= 0 && p < (data->win_width * data->win_height * 4) &&
x < data->win_width && y < data->win_height && x > 0))
	{
		data->data[p] = 255 * color * data->r;
		data->data[p + 1] = 255 * color * data->g;
		data->data[p + 2] = 250 * color * data->b;
	}
}

void	ft_create_image(t_data **data, int n)
{
	int		sizeline;
	int		endian;
	int		bpp;

	if (n == 1)
	{
		(*data)->img = mlx_new_image((*data)->mlx,
(*data)->win_width, (*data)->win_height);
		(*data)->data = mlx_get_data_addr((*data)->img,
&bpp, &sizeline, &endian);
	}
	if (n == 2)
	{
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img, 0, 0);
		mlx_destroy_image((*data)->mlx, (*data)->img);
	}
}

void	ft_put_menu(t_data **data)
{
	mlx_string_put((*data)->mlx, (*data)->win, 20, 20, 0x0000FF,
ft_strjoin("Number of threads used: ", ft_itoa((*data)->threads)));
	mlx_string_put((*data)->mlx, (*data)->win, 20, 35, 0x0000FF,
ft_strjoin("Iterations: ", ft_itoa((*data)->max)));
	mlx_string_put((*data)->mlx, (*data)->win, 20, 50, 0x0000FF,
"Change color: R(R,T) G(G,H) B(B,N).");
	mlx_string_put((*data)->mlx, (*data)->win, 20, 65, 0x0000FF,
"Move: arrow keys.");
	mlx_string_put((*data)->mlx, (*data)->win, 20, 80, 0x0000FF,
"Select fractal: 1-Mandelbrot, 2-Julia, 3-Burningship.");
	mlx_string_put((*data)->mlx, (*data)->win, 20, 95, 0x0000FF,
	"4-Brain, 5-Brain_1, 6-Juliav");
}

int		key_x(t_data **data)
{
	(*data)->scale = 0;
	exit(0);
	return (0);
}
