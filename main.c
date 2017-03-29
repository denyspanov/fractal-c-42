
#include "fractal.h"
#include <pthread.h>

void	ft_put_px(t_data **data, int x, int y, double color)
{
	int p;

	p = (x * 4) + (y * 5120);
	if (p >= 0 && p < (3686400) && x < 1280 && y < 720 && x > 0)
	{
		(*data)->data[p] = 40 * color;
		(*data)->data[p + 1] = 10 * color;
		(*data)->data[p + 2] = 50 * color;
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



/*
// I chose to represent pixels as int[2] and complex numbers as double[2]
// Here are the indexes to access pixel and complex numebers arrays:

# define X      0
# define Y      1
# define R      0   // real part
# define I      1   // imaginary part

c[R] = (pixel[X] - windowWidth) / (zoom * windowWidth);
c[I] = (pixel[Y] - windowHeight) / (zoom * windowHeight);
z[R] = 0.0f;
z[I] = 0.0f;
i = 0;
while (z[R] * z[R] + z[I] * z[I] < 4 && ++i < maxIterations)
{
tmp = z[R] * z[R] - z[I] * z[I] + c[R];
z[I] = z[R] * z[I] + z[R] * z[I] + c[I];
z[R] = tmp;
}
if (i < maxIterations)
{
// get pixel color
// call to draw function
}
*/

/*void	mandelbrot(t_data **data)
{
	int x1 = 0;
	int y1 = 0;
	int d_x;
	int d_y = -1;
	double tmp;
	double c_r = (x1 - (*data)->win_width) / ((*data)->scale * (*data)->win_width);
	double c_i = (y1 - (*data)->win_height) / ((*data)->scale * (*data)->win_height);
	double x = 0.0;
	double y = 0.0;
	int i;
	ft_create_image(&(*data), 1);
	while (++d_y < (*data)->win_height)
	{
		d_x = -1;
		while (++d_x < (*data)->win_width)
		{
			c_r = (d_x - (*data)->win_width) / ((*data)->scale * (*data)->win_width);
			c_i = (d_y - (*data)->win_height) / ((*data)->scale * (*data)->win_height);
			i = 0;
			x = 0;
			y = 0;
			while (x * x + y * y < 4 && i < 100) {
				tmp = x * x - y * y + c_r;
				y = 2 * x * y + c_i;
				x = tmp;
				i++;
			}
			if (i < 100)
				ft_put_px(&(*data), d_x, d_y, i);
		}
	}
	ft_create_image(&(*data), 2);
}*/


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
			double z_n;

			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < (*data)->max)
			{
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < (*data)->max)
				ft_put_px(&(*data),col,row, iteration + 1 - (log(2) / y) / log (2));
			else
				ft_put_px(&(*data),col,row, 0);
		}
	ft_create_image(&(*data), 2);
}

void burning_ship(t_data **data)
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
			double z_n;
			while (x*x+y*y <= 9 && iteration < (*data)->max)
			{
				double tmp = y;
				y = fabs((double)(x * y + x * y + c_im));
				x = fabs((double)(x * x - tmp * tmp + c_re));
				iteration++;
			}
			z_n = sqrt(x*x+y*y);
			if (iteration < (*data)->max)
				ft_put_px(&(*data),col,row, iteration + 1 - (log(2) / z_n) / log (2));
			else
				ft_put_px(&(*data),col,row, 0);
		}
	ft_create_image(&(*data), 2);
}

void newton(t_data **data)
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
			double tmp = 1.0;
			while (tmp > 0.000001 && iteration < (*data)->max)
			{
				double x_old = x;
				double y_old = y;
				tmp = (x * x + y * y) * (x * x + y * y);
				x = (2 * x * tmp + x * x - y * y) / (3.0 * tmp);
				y = (2 * y * (tmp - x_old)) / (3.0 * tmp);
				tmp = (x - x_old) * (x - x_old) + (y - y_old) * (y - y_old);
				iteration++;
			}
			if (iteration < (*data)->max)
				ft_put_px(&(*data),col,row, iteration + 1 - (log(2) / x) / log (2));
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
	cRe = -0.47;
	cIm = 0.544992;
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
	if (keycode == 100)
		(*data)->scale *= 2;
	if (keycode == 99)
		(*data)->scale /= 2;
	return (0);
}

int		loop_event(t_data **data)
{
	burning_ship(&(*data));
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