/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:43:02 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/23 15:43:40 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_info *info)
{
	int	target;
	int	index;

	target = 0;
	while (target < info->count)
	{
		index = target + 1;
		while (index < info->count)
		{
			if (info->stack[target] < info->stack[index])
				return (0);
			index++;
		}
		target++;
	}
	return (1);
}

void	check_dup(t_info *info)
{
	int	target;
	int	index;

	target = 0;
	while (target < info->count)
	{
		index = target + 1;
		while (index < info->count)
		{
			if (info->stack[target] == info->stack[index])
				error();
			index++;
		}
		target++;
	}
}
