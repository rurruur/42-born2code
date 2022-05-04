/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:17 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/29 22:35:10 by nakkim           ###   ########.fr       */
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

void draw_map(void *mlx_ptr, void *win_ptr, t_map map)
{
	int		x;
	int		y;
	int		row_index;
	int		col_index;


	col_index = 0;
	y = 100;
	while (col_index++ < map.col_size)
	{
		x = 100 + PIXEL;
		row_index = 0;
		while (++row_index < map.row_size)
		{
			bresenham((x - PIXEL), y, x, y, mlx_ptr, win_ptr);
			x += PIXEL;
		}
		y += PIXEL;
	}
	row_index = 0;
	x = 100;
	while (row_index++ < map.row_size)
	{
		col_index = 0;
		y = 100 + PIXEL;
		while (++col_index < map.col_size)
		{
			bresenham(x, (y - PIXEL), x, y, mlx_ptr, win_ptr);
			y += PIXEL;
		}
		x += PIXEL;
	}
}

void	createMap(char* map_file, t_map *map)
{
	int		fd;
	char	*result;
	int		row_max;
	int		row;
	int		col;
	int		index;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit(1);
	row_max = 0;
	col = 0;
	result = get_next_line(fd);
	while (result)
	{
		index = 0;
		row = 0;
		while (result[index])
		{
			while ((result[index] >= '0' && result[index] <= '9') || result[index] == '-')
				index++;
			row++;
			while (result[index] == ' ' || result[index] == '\n')
				index++;
		}
		if (row_max < row)
			row_max = row;
		col++;
		free(result);
		result = get_next_line(fd);
	}
	close(fd);
	map->col_size = col;
	map->row_size = row_max;
	printf("row: %d, col:%d\n", row_max, col);
	map->info = (int**)malloc(sizeof(int*) * col);
	if (map->info == NULL)
		exit(1);
	index = 0;
	while (index < col)
		map->info[index++] = (int*)malloc(sizeof(int) * row_max);
}

void	getMapInfo(char *map_file, t_map *map)
{
	int		fd;
	char	*result;
	int		row;
	int		col;
	int		index;
	int		flag;
	int		num;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		exit(1);
	col = 0;
	result = get_next_line(fd);
	while (result)
	{
		index = 0;
		row = 0;
		flag = 1;
		while (result[index])
		{
			flag = 1;
			num = 0;
			if (result[index] == '-')
			{
				flag = -flag;
				index++;
			}
			while ((result[index] >= '0' && result[index] <= '9'))
			{
				num = num * 10 + result[index] - '0';
				index++;
			}
			map->info[col][row] = num * flag;
			row++;
			while (result[index] == ' ' || result[index] == '\n')
				index++;
		}
		if (row < map->row_size)
			map->info[col][row++] = -2147483647;
		col++;
		free(result);
		result = get_next_line(fd);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_map	map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*param;
	t_bre	bre;

	if (argc != 2)
		return (0);
	// julia 같은 맵..안됨ㅡㅡ
	createMap(argv[1], &map);
	getMapInfo(argv[1], &map);
	
	param = NULL;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, map.row_size * PIXEL + 200, map.col_size * PIXEL + 200, TITLE);
	mlx_key_hook(win_ptr, key_hook, param);
	// x 클릭도 추가
	mlx_clear_window(mlx_ptr, win_ptr);

	bre.x = 10;
	bre.y = 10;
	// Bresenham(&bre, 20, 20, mlx_ptr, win_ptr);

	draw_map(mlx_ptr, win_ptr, map);

	// 이미지를 조작해보자..
	// void	*img_ptr = mlx_new_image(mlx_ptr, 200, 300);
	// int	bits_per_pixel = 16;
	// int	size_line = 200;
	// mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, NULL);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 10, 20);
	// 그만해보자...

	mlx_loop(mlx_ptr);
	// mlx_loop_hook(mlx_ptr, key_hook, param);
	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	free(map.info);
	return (0);
}