#include "fractal.h"

void	errors(int i)
{
	if (i == 1)
		ft_putstr("Usage: ./fractal [fractal]\nSelect: mandelbrot, julia, burningship.\n");
	if (i == 2)
		ft_putstr("Fractals available: mandelbrot, julia, burningship.\n");
	exit (0);
}