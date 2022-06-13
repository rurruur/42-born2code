/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:20:08 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/13 23:13:34 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TITLE "hi"
# define ESC 53
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define EXIT_BTN 17
# define PIXEL 64
# define START 'P'
# define END 'E'
# define COLLECTION 'C'

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>	// perror, strerror
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./minilibx_mms/mlx.h"

typedef struct s_img
{
	void	*man;
	void	*wall;
	void	*road;
	void	*collection;
	void	*end;
}	t_img;

typedef struct s_solong
{
	char	**map;
	int		width;
	int		height;
	int		collections;
	int		move;
	t_img	imgs;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_solong;

void	error(char *errorMsg);
int		is_valid_map(t_solong *info);

#endif