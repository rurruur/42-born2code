/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:19 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/26 23:02:58 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h> // open
# include <unistd.h> // read, write, close
# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // perror, strerror
# include <math.h>

# define SIZE_X 1000
# define SIZE_Y 800
# define TITLE "hi"
# define ESC 53

typedef struct coordinate
{
	int	x;
	int	y;
	int	z;
}	t_coor;

typedef struct bresenham
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	distance;
}	t_bre;

typedef struct map
{
	int	**info;
	int	col_size;
	int	row_size;
}	t_map;

void	bresenham(int x0, int y0, int x1, int y1, void* mlx_ptr, void* win_ptr);

#endif