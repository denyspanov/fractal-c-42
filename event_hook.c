#include "fractal.h"

int		key_f(int keycode, t_data **data)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT)
		(*data)->x_pos += 0.1 / (*data)->scale;
	if (keycode == LEFT)
		(*data)->x_pos -= 0.1 / (*data)->scale;
	if (keycode == DOWN)
		(*data)->y_pos += 0.1 / (*data)->scale;
	if (keycode == UP)
		(*data)->y_pos -= 0.1/ (*data)->scale;
	if (keycode == PLUS_N)
		(*data)->scale += (*data)->scale * 0.8;
	if (keycode == MINUS_N && (*data)->scale > 1.5)
		(*data)->scale -= (*data)->scale * 0.8;
	if (keycode == PLUS_K)
		(*data)->max += 10;
	if (keycode == MINUS_K)
		(*data)->max -= 10;
	if (keycode == ONE_N && (*data)->threads > 1)
		(*data)->threads -= 1;
	if (keycode == TWO_N && (*data)->threads < 4)
		(*data)->threads += 1;
	printf("%d\n",keycode);
	return (0);
}

int		mouse_hook(int x, int y, t_data **data)
{
	if (x > -1 && x < 1281 && y > -1 && y < 721) {
		(*data)->mouse_y = y / 720;
		(*data)->mouse_x = x / 1280;
		printf("y: %d x: %d\n",y,x);
	}
}