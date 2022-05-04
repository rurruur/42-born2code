# include "fdf.h"

void	plotLineLow(t_coor curr, t_coor next, void* mlx_ptr, void* win_ptr)
{
	int	dx;
	int	dy;
	int	yi;
	int	distance;

	yi = 1;
	dx = next.x - curr.x;
	dy = next.y - curr.y;
	if (dy < 0)
	{
		yi = -yi;
		dy = -dy;
	}
	distance = 2 * dy - dx;
	while (curr.x <= next.x)
	{
		mark_dot(mlx_ptr, curr.x, curr.y, 0xabcdef, win_ptr);
		// mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0x00FFFFFF);
		curr.x++;
		if (distance < 0)
			distance += 2 * dy;
		else
		{
			distance += 2 * (dy - dx);
			curr.y += yi;
		}
	}
}

void	plotLineHigh(t_coor curr, t_coor next, void* mlx_ptr, void* win_ptr)
{
	int	dx;
	int	dy;
	int	xi;
	int	distance;

	xi = 1;
	dx = next.x - curr.x;
	dy = next.y - curr.y;
	if (dx < 0)
	{
		xi = -xi;
		dx = -dx;
	}
	distance = 2 * dx - dy;
	while (curr.y <= next.y)
	{
		mark_dot(mlx_ptr, curr.x, curr.y, 0xabcdef, win_ptr);
		// mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0x00FFFFFF);
		curr.y++;
		if (distance < 0)
			distance += 2 * dx;
		else
		{
			distance += 2 * (dx - dy);
			curr.x += xi;
		}
	}
}

void	bresenham(t_coor curr, t_coor next, void* mlx_ptr, void* win_ptr)
{
	if (abs(next.x - curr.x) > abs(next.y - curr.y))
	{
		if (curr.x < next.x)
			plotLineLow(curr, next, mlx_ptr, win_ptr);
		else
			plotLineLow(next, curr, mlx_ptr, win_ptr);
	}
	else
	{
		if (curr.y < next.y)
			plotLineHigh(curr, next, mlx_ptr, win_ptr);
		else
			plotLineHigh(next, curr, mlx_ptr, win_ptr);
	}
}