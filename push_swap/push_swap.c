/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:35:21 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/10 17:05:56 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*curr = stack->list;
	puts("=======");
	for (int i = 0; i < stack->size; i++)
	{
		printf("[%d] %d [%d]\n", curr->prev->val, curr->val, curr->next->val);
		curr = curr->next;
	}
	puts("");
}

void	print_cmd(t_cmd *cmds)
{
	while (cmds != NULL)
	{
		printf("%s\n", cmds->name);
		cmds = cmds->next;
	}
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

void	sort(t_info *info, int left, int right)
{
	int		pivot;
	int		count;

	pivot = info->sorted_arr[(right - left) / 2];
	printf("pivot: %d\n", pivot);
	count = info->stack_a->size;
	while (count-- > 0)
	{

		if (info->stack_a->list->val <= pivot)
			push(info, info->stack_a, info->stack_b, "pb");
		else
			rotate(info, info->stack_a, "ra");
	}
	print_stack(info->stack_a);
	print_stack(info->stack_b);
	return ;
	sort(info, (right - left) / 2 + 1, right);
	sort(info, left, (right - left) / 2);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 2)
		return (0);
	set_info(&info, argc, argv);
	print_stack(info.stack_a);
	quick_sort(info.sorted_arr, 0, info.count - 1);

	sort(&info, 0, info.count - 1);

	print_cmd(info.cmds);

	return (0);
}
