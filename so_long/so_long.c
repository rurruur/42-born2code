/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:20:12 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/13 23:32:39 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_info(t_solong *info, char *file)
{
	int		fd;
	char	*result;
	int		width;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	// gnl 에러 확인
	result = get_next_line(fd);
	height = 0;
	while (result)
	{
		width = 0;
		while (result[width])
			width++;
		info->width = width;
		height++;
		free(result);
		result = get_next_line(fd);
	}
	info->height = height;
	close(fd);
	info->move = 0;
}

void	get_map(t_solong *info, char *file)
{
	int		fd;
	char	*result;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	height = 0;
	info->map = (char **)malloc(sizeof(char *) * info->height);
	result = get_next_line(fd);
	while (height < info->height)
	{
		// parse map
		info->map[height] = ft_strdup(result);
		height++;
		free(result);
		result = get_next_line(fd);
	}
	close(fd);
}

void	put_imgs(t_solong *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == START)
			{
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->imgs.man, j * PIXEL, i * PIXEL);
			}
			else if (info->map[i][j] == END)
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->imgs.end, j * PIXEL, i * PIXEL);
			else if (info->map[i][j] == COLLECTION)
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->imgs.collection, j * PIXEL, i * PIXEL);
			else if (info->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->imgs.wall, j * PIXEL, i * PIXEL);
			else
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->imgs.road, j * PIXEL, i * PIXEL);
		}
	}
}

int	destroy_window(t_solong* info)
{
	(void)info;
	exit(0);
}

void	change_map(t_solong *info, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == START)
				break ;
		}
		if (info->map[i][j] == START)
			break ;
	}
	if (y)
	{
		if (info->map[i + y][j] == '1')
			return ;
		if (info->map[i + y][j] == COLLECTION)
		{
			(info->collections)--;
		}
		else if (info->map[i + y][j] == END && info->collections == 0)
		{
			puts("end\n");
			destroy_window(info);
		}
		if (info->map[i + y][j] != END)
		{
			info->map[i][j] = '0';
			info->map[i + y][j] = START;
		}
	}
	else
	{
		if (info->map[i][j + x] == '1')
			return ;
		if (info->map[i][j + x] == COLLECTION)
		{
			(info->collections)--;
		}
		else if (info->map[i][j + x] == END && info->collections == 0)
		{
			puts("end\n");
			destroy_window(info);
		}
		if (info->map[i][j + x] != END)
		{
			info->map[i][j] = '0';
			info->map[i][j + x] = START;
		}
	}
}

int	key_hook(int keycode, t_solong *info)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == UP || keycode == LEFT
		|| keycode == DOWN || keycode == RIGHT)
	{
		(info->move)++;
		printf("%d, col: %d\n", info->move, info->collections);
		if (keycode == UP)
			change_map(info, 0, -1);
		else if (keycode == DOWN)
			change_map(info, 0, 1);
		else if (keycode == RIGHT)
			change_map(info, 1, 0);
		else if (keycode == LEFT)
			change_map(info, -1, 0);
		put_imgs(info);
	}
	return (1);
}

void	set_imgs(t_solong *info)
{
	int	size;

	size = 64;
	info->imgs.end = mlx_xpm_file_to_image(info->mlx_ptr, "./imgs/end.xpm", &size, &size);
	info->imgs.road = mlx_xpm_file_to_image(info->mlx_ptr, "./imgs/road.xpm", &size, &size);
	info->imgs.wall = mlx_xpm_file_to_image(info->mlx_ptr, "./imgs/wall.xpm", &size, &size);
	info->imgs.collection = mlx_xpm_file_to_image(info->mlx_ptr, "./imgs/collection.xpm", &size, &size);
	info->imgs.man = mlx_xpm_file_to_image(info->mlx_ptr, "./imgs/man.xpm", &size, &size);
}

int	main(int argc, char **argv)
{
	t_solong	*info;
	int	i;
	int	j;

	if (argc != 2)
		return (0);
	info = (t_solong *)malloc(sizeof(t_solong));
	set_map_info(info, argv[1]);
	get_map(info, argv[1]);
	if (!is_valid_map(info))
		exit(1);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->width * PIXEL, info->height * PIXEL, TITLE);
	set_imgs(info);

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (info->map[i][++j])
			mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->imgs.road, j * PIXEL, i * PIXEL);
	}
	
	put_imgs(info);
	mlx_hook(info->win_ptr, 2, 0, key_hook, info);
	mlx_hook(info->win_ptr, EXIT_BTN, 0, destroy_window, info);
	mlx_loop(info->mlx_ptr);

	return (0);
}