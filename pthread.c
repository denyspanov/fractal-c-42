/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:41:48 by dpanov            #+#    #+#             */
/*   Updated: 2017/04/05 16:38:20 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	*thr_func(void *arg)
{
	t_thread_data *data;

	data = (t_thread_data *)arg;
	if (data->data->fract == 1)
		mandelbrot(data->data, data->x_start, data->x_end, data->y_start);
	else if (data->data->fract == 3)
		burningship(data->data, data->x_start, data->x_end, data->y_start);
	else if (data->data->fract == 2)
		julia(data->data, data->x_start, data->x_end, data->y_start);
	else if (data->data->fract == 4)
		brain(data->data, data->x_start, data->x_end, data->y_start);
	else if (data->data->fract == 5)
		brain_v(data->data, data->x_start, data->x_end, data->y_start);
	else if (data->data->fract == 6)
		juliav(data->data, data->x_start, data->x_end, data->y_start);
	pthread_exit(NULL);
}

int		mult_thrd(t_data **data)
{
	pthread_t		thr[(*data)->threads];
	int				i;
	t_thread_data	thr_data[(*data)->threads];

	ft_create_image(&(*data), 1);
	i = -1;
	while (++i < (*data)->threads)
	{
		thr_data[i].tid = i;
		thr_data[i].data = (*data);
		thr_data[i].x_start = (*data)->win_width / (*data)->threads * i;
		thr_data[i].x_end = (*data)->win_width / (*data)->threads * (i + 1);
		thr_data[i].y_start = 0;
		thr_data[i].y_end = (*data)->win_height;
		pthread_create(&thr[i], NULL, thr_func, &thr_data[i]);
	}
	i = -1;
	while (++i < (*data)->threads)
		pthread_join(thr[i], NULL);
	ft_create_image(&(*data), 2);
	ft_put_menu(&(*data));
	return (0);
}
