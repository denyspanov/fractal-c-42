#include "fractal.h"

int		key_f(int keycode, t_data **data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		(*data)->x_pos += 0.1 / (*data)->scale;
	if (keycode == 123)
		(*data)->x_pos -= 0.1 / (*data)->scale;
	if (keycode == 125)
		(*data)->y_pos += 0.1 / (*data)->scale;
	if (keycode == 126)
		(*data)->y_pos -= 0.1/ (*data)->scale;
	if (keycode == 69)
		(*data)->scale += 0.5;
	if (keycode == 78)
		(*data)->scale -= 0.5;
	if (keycode == 24)
		(*data)->max += 10;
	if (keycode == 25)
		(*data)->max -= 10;
	return (0);
}

int		mouse_hook(int x, int y, t_data **data)
{
	if (x > -1 && x < 1281 && y > -1 && y < 721) {
		(*data)->mouse_y = y / 720;
		(*data)->mouse_x = x / 1280;
	}
}