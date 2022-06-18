/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:46:59 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/18 15:10:49 by nakkim           ###   ########.fr       */
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

void	print_changed_map(t_solong *info)
{
	char	*move;

	(info->move)++;
	move = ft_itoa(info->move);
	write(1, move, ft_strlen(move));
	write(1, "\n", 1);
	free(move);
	put_imgs(*info);
}

int	key_hook(int keycode, t_solong *info)
{
	int		changed;

	if (keycode == ESC)
		destroy_window(info);
	changed = 0;
	if (keycode == UP || keycode == LEFT
		|| keycode == DOWN || keycode == RIGHT)
	{
		if (keycode == UP)
			changed = change_map(info, 0, -1);
		else if (keycode == DOWN)
			changed = change_map(info, 0, 1);
		else if (keycode == RIGHT)
			changed = change_map(info, 1, 0);
		else if (keycode == LEFT)
			changed = change_map(info, -1, 0);
		if (changed)
			print_changed_map(info);
	}
	return (1);
}

int	destroy_window(t_solong *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}
