/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:16:02 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/18 15:09:34 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *errorMsg)
{
	write(1, "Error\n", 6);
	write(1, errorMsg, ft_strlen(errorMsg));
	write(1, "\n", 1);
	exit(1);
}

int	is_rectangle(t_solong *info)
{
	int	i;

	i = -1;
	while (++i < info->height)
		if (info->width != (int)ft_strlen(info->map[i]))
			return (0);
	return (1);
}

int	is_surrounded(t_solong *info)
{
	int	i;
	int	width_tmp;

	i = -1;
	while (++i < info->height)
	{
		if (i == 0 || i == info->height - 1)
		{
			width_tmp = -1;
			while (info->map[i][++width_tmp])
				if (info->map[i][width_tmp] != '1')
					return (0);
		}
		else
		{
			if (info->map[i][0] != '1' || info->map[i][info->width - 1] != '1')
				return (0);
		}
	}
	return (1);
}

int	is_valid_object(t_solong *info, int start, int end)
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
				start++;
			else if (info->map[i][j] == END)
				end++;
			else if (info->map[i][j] == COLLECTION)
				(info->collections)++;
			else if (info->map[i][j] != '1' && info->map[i][j] != '0')
				error("잘못된 문자가 포함되어 있습니다.");
		}
	}
	if (start != 1 || end == 0 || info->collections == 0)
		return (0);
	return (1);
}

void	validate_map(t_solong *info)
{
	if (!is_rectangle(info))
		error("직사각형이 아닙니다.");
	if (!is_surrounded(info))
		error("벽으로 둘러쌓여 있지 않습니다.");
	if (!is_valid_object(info, 0, 0))
		error("오브젝트 에러");
}
