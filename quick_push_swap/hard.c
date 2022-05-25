/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:40:49 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/23 15:44:49 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_info *info)
{
	if (info->stack[2] < info->stack[1] && info->stack[2] < info->stack[0])
	{
		reverse_rotate_a(info);
		swap_a(info);
	}
	else if ((info->stack[2] > info->stack[1]
			&& info->stack[2] < info->stack[0])
		|| (info->stack[2] < info->stack[1]
			&& info->stack[2] > info->stack[0]))
	{
		if (info->stack[1] < info->stack[0])
			swap_a(info);
		else
			reverse_rotate_a(info);
	}
	else if (info->stack[2] > info->stack[1] && info->stack[2] > info->stack[0])
	{
		if (info->stack[1] < info->stack[0])
			rotate_a(info);
		else
		{
			swap_a(info);
			reverse_rotate_a(info);
		}
	}
}

void	set_top_custom(t_info *info, int num)
{
	int	index;

	index = 0;
	while (info->stack[index] != num)
		index++;
	if (index < (info->a + 1) / 2)
		while (info->stack[info->a] != num)
			reverse_rotate_a(info);
	else
		while (info->stack[info->a] != num)
			rotate_a(info);
}

void	sort_5(t_info *info)
{
	set_top_custom(info, 0);
	push_b(info);
	set_top_custom(info, 1);
	push_b(info);
	if (!(info->stack[2] == 2 && info->stack[1] == 3 && info->stack[0] == 4))
		sort_3(info);
	push_a(info);
	push_a(info);
}

void	hard_sort(t_info *info)
{
	if (info->count == 2)
		rotate_a(info);
	else if (info->count == 3)
		sort_3(info);
	else if (info->count == 5)
		sort_5(info);
}
