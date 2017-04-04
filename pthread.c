
#include "fractal.h"

void *thr_func(void *arg) {
	t_thread_data *data = (t_thread_data *)arg;
	t_data *ss = data->data;
	if (data->data->fract == 1)
		mandelbrot(ss, data->x_start, data->x_end, data->y_start);
	else if (data->data->fract == 3)
		burningship(ss, data->x_start, data->x_end, data->y_start);
}

int mult_thrd(t_data **data)
{
	pthread_t thr[(*data)->threads];
	int i;
	int rc;
	t_thread_data thr_data[(*data)->threads];
	ft_create_image(&(*data), 1);
	for (i = 0; i < (*data)->threads; i++)
	{
		thr_data[i].tid = i;
		thr_data[i].data = (*data);
		thr_data[i].x_start = (*data)->win_width / (*data)->threads * i;
		thr_data[i].x_end = (*data)->win_width / (*data)->threads * (i + 1);
		thr_data[i].y_start = 0;
		thr_data[i].y_end = (*data)->win_height;
		if ((rc = pthread_create(&thr[i], NULL, thr_func, &thr_data[i]))) {
			fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
			return EXIT_FAILURE;
		}
	}
	for (i = 0; i < (*data)->threads; i++)
	{
		pthread_join(thr[i], NULL);
	}
	ft_create_image(&(*data), 2);
    ft_put_menu(&(*data));
	return EXIT_SUCCESS;
}