/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:29 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 23:03:24 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmds(t_cmd *cmds)
{
	t_cmd	*curr;

	if (cmds == NULL)
		return ;
	curr = cmds;
	printf("%s\n", curr->name);
	curr = curr->next;
	while (curr != cmds)
	{
		printf("%s\n", curr->name);
		curr = curr->next;
	}
}

void	sort(t_info *info)
{
	int	max_bits;
	int	shift;
	int	count;

	max_bits = sizeof(int) * 8;
	shift = -1;
	while (++shift < max_bits && !is_sorted(info->stack_a, 1))
	{
		count = -1;
		while (++count < info->size)
		{
			if (((info->stack_a->head->val >> shift) & 1) == 1)
				rotate(info, info->stack_a, "ra");
			else
				push(info, info->stack_a, info->stack_b, "pb");
		}
		while (info->stack_a->size != info->size)
			push(info, info->stack_b, info->stack_a, "pa");
	}
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 2)
		return (0);
	set_info(&info, argc, argv);
	check_dup(&info);
	if (is_sorted(info.stack_a, 1))
		return (0);
	if (info.size <= 5)
		hard_sort(&info);
	else
	{
		quick_sort(info.sorted_arr, 0, info.size - 1);
		process_indexing(&info);
		sort(&info);
	}
	print_cmds(info.cmds);
	return (0);
}
