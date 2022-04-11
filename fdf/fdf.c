/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:17 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/12 00:31:24 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char** argv)
{
	void*	mlx_ptr;
	void*	win_ptr;

	mlx_ptr = mlx_init();
	printf("%p\n", mlx_ptr);
	win_ptr = mlx_new_window(mlx_ptr, SIZE_X, SIZE_Y, TITLE);
	printf("%p\n", win_ptr);
	mlx_loop(mlx_ptr);
	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}