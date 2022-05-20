/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:29 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/20 21:16:57 by nakkim           ###   ########.fr       */
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

void	print_stack(t_info info)
{
	int	index;

	index = 0;
	puts("----------------");
	printf("a: %d, b: %d\n", info.a, info.a + 1);
	printf("[bottom] ");
	if (index > info.a)
		printf("[top] ");
	while (index < info.count)
	{
		printf("%d ", info.stack[index]);
		if (index == info.a)
			printf("[top] ");
		index++;
	}
	puts("[bottom]");
	puts("----------------");
}

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

void	sort_3(t_info *info)
{
	if (info->stack[2] < info->stack[1] && info->stack[2] < info->stack[0])
	{
		reverse_rotate_a(info);
		swap_a(info);
	}
	else if ((info->stack[2] > info->stack[1] && info->stack[2] < info->stack[0]) || (info->stack[2] < info->stack[1] && info->stack[2] > info->stack[0]))
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

int	main(int argc, char **argv)
{
	t_info	info;

	set_info(&info, argc, argv);
	check_dup(&info);
	indexing(&info);
	// print_stack(info);
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
