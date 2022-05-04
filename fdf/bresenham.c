# include "fdf.h"

void	plotLineLow(int x0, int y0, int x1, int y1, void* mlx_ptr, void* win_ptr)
{
	int	dx;
	int	dy;
	int	yi;
	int	distance;

	yi = 1;
	dx = x1 - x0;
	dy = y1 - y0;
	if (dy < 0)
	{
		yi = -yi;
		dy = -dy;
	}
	distance = 2 * dy - dx;
	while (x0 <= x1)
	{
		mark_dot(mlx_ptr, x0, y0, 0xabcdef, win_ptr);
		// mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0x00FFFFFF);
		x0++;
		if (distance < 0)
			distance += 2 * dy;
		else
		{
			distance += 2 * (dy - dx);
			y0 += yi;
		}
	}
}

void	plotLineHigh(int x0, int y0, int x1, int y1, void* mlx_ptr, void* win_ptr)
{
	int	dx;
	int	dy;
	int	xi;
	int	distance;

	xi = 1;
	dx = x1 - x0;
	dy = y1 - y0;
	if (dx < 0)
	{
		xi = -xi;
		dx = -dx;
	}
	distance = 2 * dx - dy;
	while (y0 <= y1)
	{
		mark_dot(mlx_ptr, x0, y0, 0xabcdef, win_ptr);
		// mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0x00FFFFFF);
		y0++;
		if (distance < 0)
			distance += 2 * dx;
		else
		{
			distance += 2 * (dx - dy);
			x0 += xi;
		}
	}
}

void	bresenham(int x0, int y0, int x1, int y1, void* mlx_ptr, void* win_ptr)
{
	if (abs(x1 - x0) > abs(y1 - y0))
	{
		if (x0 < x1)
			plotLineLow(x0, y0, x1, y1, mlx_ptr, win_ptr);
		else
			plotLineLow(x1, y1, x0, y0, mlx_ptr, win_ptr);
	}
	else
	{
		if (y0 < y1)
			plotLineHigh(x0, y0, x1, y1, mlx_ptr, win_ptr);
		else
			plotLineHigh(x1, y1, x0, y0, mlx_ptr, win_ptr);
	}
}