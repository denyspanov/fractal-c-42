#include "fractal.h"

void	ft_put_px(t_data *data, int x, int y, double color)
{
	int p;


	p = (x * 4) + (y * data->win_width * 4);
	if (p >= 0 && p < (data->win_width * data->win_height * 4) && x < data->win_width && y < data->win_height && x > 0)
	{
		data->data[p] = 10 * color;
		data->data[p + 1] = 0 * color;
		data->data[p + 2] = 5 * color;
	}
}

void	ft_create_image(t_data **data, int n)
{
	int		sizeline;
	int		endian;
	int		bpp;

	if (n == 1)
	{
		(*data)->img = mlx_new_image((*data)->mlx,(*data)->win_width, (*data)->win_height);
		(*data)->data = mlx_get_data_addr((*data)->img,
										  &bpp, &sizeline, &endian);
	}
	if (n == 2)
	{
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img, 0, 0);
		mlx_destroy_image((*data)->mlx, (*data)->img);
	}
}