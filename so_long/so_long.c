/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:20:12 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/17 15:32:56 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_road(t_solong info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info.height)
	{
		j = -1;
		while (info.map[i][++j])
			mlx_put_image_to_window(info.mlx_ptr, info.win_ptr,
				info.imgs.road, j * PIXEL, i * PIXEL);
	}
}

int	main(int argc, char **argv)
{
	t_solong	info;

	if (argc != 2)
		return (0);
	set_map_info(&info, argv[1]);
	get_map(&info, argv[1]);
	validate_map(&info);
	info.mlx_ptr = mlx_init();
	if (info.mlx_ptr == 0)
		error("mlx_init() fail.");
	info.win_ptr = mlx_new_window(info.mlx_ptr,
			info.width * PIXEL, info.height * PIXEL, TITLE);
	if (info.win_ptr == 0)
		error("mlx_new_window() fail.");
	set_imgs(&info);
	paint_road(info);
	put_imgs(info);
	mlx_hook(info.win_ptr, 2, 0, key_hook, &info);
	mlx_hook(info.win_ptr, EXIT_BTN, 0, destroy_window, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
