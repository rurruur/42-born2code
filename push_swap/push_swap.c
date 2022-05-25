/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:29 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 14:59:36 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_info *info)
{
	int	*sorted;
	int	index;
	int	info_index;

	sorted = (int *)malloc(sizeof(int) * info->count);
	index = -1;
	while (++index < info->count)
		sorted[index] = info->stack[index];
	quick_sort(sorted, 0, info->count - 1);
	info_index = 0;
	while (info_index < info->count)
	{
		index = 0;
		while (sorted[index] != info->stack[info_index])
			index++;
		info->stack[info_index] = index;
		info_index++;
	}
	free(sorted);
}

void	a_to_b(t_info *info)
{
	int	num;
	int	top;

	num = 0;
	while (num < info->count)
	{
		top = info->stack[info->a];
		if (top <= num)
		{
			push_b(info);
			num++;
		}
		else if (top > num && top <= num + info->chunk)
		{
			push_b(info);
			rotate_b(info);
			num++;
		}
		else
			rotate_a(info);
	}
}

void	set_top(t_info *info)
{
	int	max;
	int	index;

	index = info->a + 1;
	max = info->count - (info->a + 1) - 1;
	while (info->stack[index] != max)
		index++;
	if (index < info->a + max / 2)
		while (info->stack[info->a + 1] != max)
			rotate_b(info);
	else
		while (info->stack[info->a + 1] != max)
			reverse_rotate_b(info);
}

void	b_to_a(t_info *info)
{
	while (info->a < info->count - 1)
	{
		set_top(info);
		push_a(info);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	set_info(&info, argc, argv);
	check_dup(&info);
	indexing(&info);
	if (is_sorted(&info))
		return (0);
	if (info.count <= 5)
		hard_sort(&info);
	else
	{
		a_to_b(&info);
		b_to_a(&info);
	}
	free(info.stack);
	return (0);
}
