void	ft_put_px(t_data **data, int x, int y, int color)
{
	int p;

	p = (x * 4) + (y * 5120);
	if (p >= 0 && p < (3686400) && x < 1280 && y < 720 && x > 0)
	{
		(*data)->data[p] = 5 * color;
		(*data)->data[p + 1] = 0 * color;
		(*data)->data[p + 2] = 0 * color;
	}
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


int main(int argc, char *argv[])
{
	screen(400, 300, 0, "Julia Set"); //make larger to see more detail!

	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
	double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
	double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
	ColorRGB color; //the RGB color value for the pixel
	int maxIterations = 300; //after how much iterations the function should stop

	//pick some values for the constant c, this determines the shape of the Julia Set
	cRe = -0.7;
	cIm = 0.27015;

	//loop through every pixel
	for(int y = 0; y < h; y++)
		for(int x = 0; x < w; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			newRe = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
			newIm = (y - h / 2) / (0.5 * zoom * h) + moveY;
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
			color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
			//draw the pixel
			pset(x, y, color);
		}
	//make the Julia Set visible and wait to exit
	redraw();
	sleep();
	return 0;
}

/*void burning_ship(t_data **data)
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
}*/

/*void newton(t_data **data)
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
}*/

/*void	julia(t_data **data)
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
}*/

void	mandelbrot(t_data **data)
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
}
