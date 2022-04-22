/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:17 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/20 15:26:55 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void* param)
{
	(void)param;
	if (keycode == ESC)
		exit(1);
	return (1);
}

void	iso(t_coor* c)
{
	int	prev_x;
	int	prev_y;

	prev_x = c->x;
	prev_y = c->y;
	c->x = (prev_x - prev_y) * cos(0.523599);
	c->y = (prev_x - prev_y) * sin(0.523599) - c->z;
}

void	draw_point(void *mlx_ptr, void *win_ptr, t_coor* c)
{
	
}

void draw_map(void *mlx_ptr, void *win_ptr, char *map_file)
{
	int		fd;
	int		i;
	char	*result;
	t_coor	coordinate;

	fd = open(map_file, O_RDONLY);
	coordinate.y = 100;
	if (fd == -1)
		exit(1);
	
	result = get_next_line(fd);
	while (result)
	{
		coordinate.y += 20;
		i = 0;
		coordinate.x = 100;
		printf("%s", result);
		while (result[i] && result[i] != '\n')
		{
			coordinate.x += 20;
			coordinate.z = result[i];
			iso(&coordinate);
			draw_point(mlx_ptr, win_ptr, &coordinate);
			i++;
		}
		free(result);
		result = get_next_line(fd);
	}
	
	close(fd);
}

// 픽셀 크기 지정
void Bresenham(t_bre* bre, int x1, int y1, void* mlx_ptr, void* win_ptr)
{
	bre->dx = x1 - bre->x;
	bre->dy = y1 - bre->y;
	bre->distance = 2 * bre->dy - bre->dx;
	while (bre->x <= x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, bre->x, bre->y, 0x00FFFFFF);
		(bre->x)++;
		if (bre->distance < 0)
			bre->distance = bre->distance + 2 * bre->dy;
		else
		{
			bre->distance = bre->distance + 2 * bre->dy - bre->dx;
			(bre->y)++;
		}
	}
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*param;
	t_bre	bre;

	if (argc != 2)
		return (0);
	param = NULL;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, SIZE_X, SIZE_Y, TITLE);
	mlx_key_hook(win_ptr, key_hook, param);
	mlx_clear_window(mlx_ptr, win_ptr);

	bre.x = 10;
	bre.y = 10;
	Bresenham(&bre, 20, 20, mlx_ptr, win_ptr);

	//draw_map(mlx_ptr, win_ptr, argv[1]);

	mlx_loop(mlx_ptr);
	// mlx_loop_hook(mlx_ptr, key_hook, param);
	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}