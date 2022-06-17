/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:46:59 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/17 15:24:16 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_imgs(t_solong s)
{
	int	j;

	while (--(s.height) >= 0)
	{
		j = -1;
		while (s.map[s.height][++j])
		{
			if (s.map[s.height][j] == PLAYER)
				mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, s.imgs.man,
					j * PIXEL, s.height * PIXEL);
			else if (s.map[s.height][j] == END)
				mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, s.imgs.end,
					j * PIXEL, s.height * PIXEL);
			else if (s.map[s.height][j] == COLLECTION)
				mlx_put_image_to_window(s.mlx_ptr, s.win_ptr,
					s.imgs.collection, j * PIXEL, s.height * PIXEL);
			else if (s.map[s.height][j] == '1')
				mlx_put_image_to_window(s.mlx_ptr, s.win_ptr,
					s.imgs.wall, j * PIXEL, s.height * PIXEL);
			else
				mlx_put_image_to_window(s.mlx_ptr, s.win_ptr,
					s.imgs.road, j * PIXEL, s.height * PIXEL);
		}
	}
}

int	key_hook(int keycode, t_solong *info)
{
	char	*move;

	if (keycode == ESC)
		exit(1);
	if (keycode == UP || keycode == LEFT
		|| keycode == DOWN || keycode == RIGHT)
	{
		(info->move)++;
		move = ft_itoa(info->move);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
		if (keycode == UP)
			change_map(info, 0, -1);
		else if (keycode == DOWN)
			change_map(info, 0, 1);
		else if (keycode == RIGHT)
			change_map(info, 1, 0);
		else if (keycode == LEFT)
			change_map(info, -1, 0);
		put_imgs(*info);
	}
	return (1);
}

int	destroy_window(t_solong *info)
{
	(void)info;
	exit(0);
}
