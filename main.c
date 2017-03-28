
#include "fractal.h"

void	ft_put_px(t_data **data, int x, int y, int color)
{
	int p;

	p = (x * 4) + (y * 5120);
	if (p >= 0 && p < (3686400) && x < 1280 && y < 720 && x > 0)
	{
		(*data)->data[p] = 5 * color;
		(*data)->data[p + 1] = 1 * color;
		(*data)->data[p + 2] = 0 * color;
	}
}

void	ft_create_image(t_data **data, int n)
{
	int		sizeline;
	int		endian;
	int		bpp;

	if (n == 1)
	{
		(*data)->img = mlx_new_image((*data)->mlx,1280, 720);
		(*data)->data = mlx_get_data_addr((*data)->img,
										  &bpp, &sizeline, &endian);
	}
	if (n == 2)
	{
		mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img, 0, 0);
		mlx_destroy_image((*data)->mlx, (*data)->img);
	}
}

void mandelbrot(t_data **data)
{
	ft_create_image(&(*data), 1);
	for (int row = 0; row < (*data)->win_height; row++)
		for (int col = 0; col < (*data)->win_width; col++)
		{
			double c_re = (col - (*data)->win_width/2.0)*4.0/(*data)->win_width;
			double c_im = (row - (*data)->win_height/2.0)*4.0/(*data)->win_width;
			c_re = c_re / (*data)->scale + (*data)->x_pos;
			c_im = c_im / (*data)->scale + (*data)->y_pos;
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < (*data)->max)
			{
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < (*data)->max)
				ft_put_px(&(*data),col,row, iteration * 2);
			else
				ft_put_px(&(*data),col,row, 0);
		}
	ft_create_image(&(*data), 2);
}

void	julia(t_data **data)
{
	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
	double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
	double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
	int maxIterations = 300; //after how much iterations the function should stop

	//pick some values for the constant c, this determines the shape of the Julia Set
	cRe = -0.7;
	cIm = 0.27015;
	ft_create_image(&(*data), 1);
	//loop through every pixel
	for(int y = 0; y < (*data)->win_height; y++)
		for(int x = 0; x < (*data)->win_width; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			newRe = 1.5 * (x - (*data)->win_width/ 2) / (0.5 * (*data)->scale * (*data)->win_width) + (*data)->x_pos;
			newIm = (y - (*data)->win_height / 2) / (0.5 * (*data)->scale * (*data)->win_height) + (*data)->y_pos;
			//i will represent the number of iterations
			int i;
			//start the iteration process
			for(i = 0; i < maxIterations; i++)
			{
				//remember value of previous iteration
				oldRe = newRe;
				oldIm = newIm;
				//the actual iteration, the real and imaginary part are calculated
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
				//if the point is outside the circle with radius 2: stop
				if((newRe * newRe + newIm * newIm) > 4) break;
			}
			//use color model conversion to get rainbow palette, make brightness black if maxIterations reached
			//draw the pixel
			ft_put_px(&(*data),x, y, i * 20);
		}
	ft_create_image(&(*data), 2);
	//make the Julia Set visible and wait to exit
}

int		key_f(int keycode, t_data **data)
{
	if (keycode == 65363)
		(*data)->x_pos += 0.1 / (*data)->scale;
	if (keycode == 65361)
		(*data)->x_pos -= 0.1/ (*data)->scale;
	if (keycode == 65364)
		(*data)->y_pos += 0.1 / (*data)->scale;
	if (keycode == 65362)
		(*data)->y_pos -= 0.1/ (*data)->scale;
	if (keycode == 100) {
		(*data)->scale *= 2;
		(*data)->max *= 2;}
	if (keycode == 99)
		(*data)->scale /= 2;
	return (0);
}

int		loop_event(t_data **data)
{
	mandelbrot(&(*data));
	return (0);
}

void	mlx_it(t_data **data)
{
	(*data)->mlx = mlx_init();
	(*data)->win = mlx_new_window((*data)->mlx,(*data)->win_width,(*data)->win_height, "Fractal");
}

void	standart_data(t_data **data)
{
	(*data)->scale = 1;
	(*data)->y_pos = 0;
	(*data)->x_pos = 0;
	(*data)->win_width = 1280;
	(*data)->win_height = 720;
	(*data)->max = 100;
}

int main()
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	standart_data(&data);
	mlx_it(&data);
	mlx_hook(data->win, 2, 3, key_f, &data);
	mlx_loop_hook(data->mlx, &loop_event, &data);
	mlx_loop(data->mlx);
	mlx_loop(data->mlx);
}
