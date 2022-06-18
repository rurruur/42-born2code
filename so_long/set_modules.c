/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:25:55 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/18 15:07:09 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_changes(t_solong *info, int x, int y)
{
	if (info->map[y][x] == '1')
		return ;
	if (info->map[y][x] == COLLECTION)
		(info->collections)--;
	else if (info->map[y][x] == END && info->collections == 0)
	{
		write(1, "Clear\n", 5);
		destroy_window(info);
	}
}

int	change_map(t_solong *info, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (info->map[i][j] == PLAYER)
				break ;
		}
		if (info->map[i][j] == PLAYER)
			break ;
	}
	process_changes(info, j + x, i + y);
	if (info->map[i + y][j + x] != END && info->map[i + y][j + x] != '1')
	{
		info->map[i][j] = '0';
		info->map[i + y][j + x] = PLAYER;
		return (1);
	}
	return (0);
}

void	set_imgs(t_solong *info)
{
	int	size;

	size = 64;
	info->imgs.end = mlx_xpm_file_to_image(info->mlx_ptr,
			"./imgs/home.xpm", &size, &size);
	info->imgs.road = mlx_xpm_file_to_image(info->mlx_ptr,
			"./imgs/road.xpm", &size, &size);
	info->imgs.wall = mlx_xpm_file_to_image(info->mlx_ptr,
			"./imgs/tree.xpm", &size, &size);
	info->imgs.collection = mlx_xpm_file_to_image(info->mlx_ptr,
			"./imgs/apple.xpm", &size, &size);
	info->imgs.man = mlx_xpm_file_to_image(info->mlx_ptr,
			"./imgs/fox.xpm", &size, &size);
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
		info->map[height] = ft_strdup(result);
		height++;
		free(result);
		result = get_next_line(fd);
	}
	close(fd);
}

void	set_map_info(t_solong *info, char *file)
{
	int		fd;
	char	*result;
	int		width;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("파일이 존재하지 않습니다.");
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
	info->collections = 0;
}
