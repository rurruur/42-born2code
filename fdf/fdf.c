/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:17 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/14 16:16:53 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hook(int keycode, void* param)
{
	(void)param;
	if (keycode == ESC)
		exit(1);
	return (1);
}

void draw_point(void *mlx_ptr, void *win_ptr, int x, int y, int z)
{
	int		i;

	i = -5;
	while (i < 5)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x + i, y, 0x00FFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, x, y + i, 0x00FFFFFF);
		i++;
	}
}

void draw_map(void *mlx_ptr, void *win_ptr, char *map_file)
{
	int		fd;
	int		x;
	int		y;
	int		i;
	char	*result;

	fd = open(map_file, O_RDONLY);
	x = 100;
	y = 200;
	if (fd == -1)
		exit(1);
	
	result = get_next_line(fd);
	while (result)
	{
		y += 10;
		i = 0;
		printf("%s", result);
		while (result[i] && result[i] != '\n')
		{
			x += 10;
			draw_point(mlx_ptr, win_ptr, x, y, result[i]);
			i++;
		}
		free(result);
		result = get_next_line(fd);
	}
	
	close(fd);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*param;

	if (argc != 2)
		return (0);
	param = NULL;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, SIZE_X, SIZE_Y, TITLE);
	mlx_key_hook(win_ptr, key_hook, param);
	mlx_clear_window(mlx_ptr, win_ptr);

	draw_map(mlx_ptr, win_ptr, argv[1]);

	mlx_loop(mlx_ptr);
	// mlx_loop_hook(mlx_ptr, key_hook, param);
	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}