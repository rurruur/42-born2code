/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:19 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/29 22:34:47 by nakkim           ###   ########.fr       */
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

# define PIXEL 30
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


typedef struct image
{
	void*	img_ptr;
	char*	buffer;
	// number of bits needed to represent a pixel color
	// (also called the depth of the image)
	int		bpp;
	// to store one line of the image in memory
	int		line_bytes;
	// little endian == 0
	int		endian;
}	t_img;

void	bresenham(int x0, int y0, int x1, int y1, void* mlx_ptr, void* win_ptr);
void	mark_dot(void *mlx_ptr, int x, int y, int color, void* win_ptr);

#endif