/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:17 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/14 15:30:28 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hook(int keycode, void* param)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		exit(1);
	return (1);
}

int	main(int argc, char** argv)
{
	void*	mlx_ptr;
	void*	win_ptr;
	void*	param;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, SIZE_X, SIZE_Y, TITLE);
	mlx_key_hook(win_ptr, key_hook, param);
	mlx_loop(mlx_ptr);
	// mlx_loop_hook(mlx_ptr, key_hook, param);
	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}