/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:20:08 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/17 15:29:30 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TITLE "so_long"
# define ESC 53
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define EXIT_BTN 17
# define PIXEL 64
# define PLAYER 'P'
# define END 'E'
# define COLLECTION 'C'

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./minilibx_opengl/mlx.h"

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
void	validate_map(t_solong *info);
int		key_hook(int keycode, t_solong *info);
int		destroy_window(t_solong *info);
void	change_map(t_solong *info, int x, int y);
void	put_imgs(t_solong s);
void	set_map_info(t_solong *info, char *file);
void	get_map(t_solong *info, char *file);
void	set_imgs(t_solong *info);
void	put_imgs(t_solong s);

#endif