/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:29 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 17:08:44 by nakkim           ###   ########.fr       */
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

int	my_strcmp(char *cmd1, char *cmd2)
{
	if (cmd1[0] == cmd2[0] && cmd1[1] == cmd2[1])
		return (1);
	return (0);
}

int	check_cmd(char *cmd)
{
	if (my_strcmp(cmd, "ra"))
		return (10);
	else if (my_strcmp(cmd, "rb"))
		return (11);
	else if (my_strcmp(cmd, "pa"))
		return (20);
	else if (my_strcmp(cmd, "pb"))
		return (21);
	return (0);
}

void	print_cmds(t_cmd *cmds)
{
	while (cmds != NULL)
	{
		if (cmds->next == NULL || !(check_cmd(cmds->name) - check_cmd(cmds->next->name) == 1
			|| check_cmd(cmds->name) - check_cmd(cmds->next->name) == -1))
		{
			printf("%s\n", cmds->name);
			cmds = cmds->next;
		}
		else
			cmds = cmds->next->next;
	}
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sorted(t_stack *stack, int flag)
{
	int		count;
	t_node	*curr;

	count = stack->size;
	curr = stack->list;
	if (flag)
	{
		while (--count)
		{
			if (curr->val > curr->next->val)
				return (0);
			curr = curr->next;
		}
	}
	else
	{
		while (--count)
		{
			if (curr->val < curr->next->val)
				return (0);
			curr = curr->next;
		}
	}
	return (1);
}

void	sort_three(t_info *info, t_stack *stack)
{
	// 1 3 2
	// 2 1 3
	// 2 3 1
	// 3 1 2
	// 3 2 1
	if (stack->list->val < stack->list->next->val && stack->list->val < stack->list->prev->val)
		
}

int	sort_a(t_info *info, int left, int right)
{	
	int		pivot;
	int		count;

	if (is_sorted(info->stack_a, 1))
		return (left - 1);
	if (right - left < 3)
	{
		sort_three(info, info->stack_a);
		return (left - 1);
	}
	pivot = left + (right - left) / 2;
	count = info->stack_a->size;
	while (count-- > 0)
	{
		if (info->stack_a->list->val <= info->sorted_arr[pivot])
			push(info, info->stack_a, info->stack_b, "pb");
		else
			rotate(info, info->stack_a, "ra");
	}
	return (sort_a(info, left + (right - left) / 2 + 1, right));
}

void	sort(t_info *info, int left, int right)
{
	int		pivot;
	int		count;
	int		last_pivot;

	if (is_sorted(info->stack_a, 1))
		return ;
	if (right - left < 3)
	{
		sort_three(info, info->stack_a);
		return ;
	}
	pivot = left + (right - left) / 2;
	count = info->stack_a->size;
	while (count-- > 0)
	{

		if (info->stack_a->list->val <= info->sorted_arr[pivot])
			push(info, info->stack_a, info->stack_b, "pb");
		else
			rotate(info, info->stack_a, "ra");
	}
	last_pivot = sort_a(info, left + (right - left) / 2 + 1, right);
	// b스택 -> a스택
	while (last_pivot > pivot)
	{
		count = 2;
		while (count)
		{
			if (info->stack_b->list->val >= info->sorted_arr[last_pivot - 1]
				&& info->stack_b->list->val <= info->sorted_arr[last_pivot])
			{
				push(info, info->stack_b, info->stack_a, "pa");
				count--;
			}
			else
				rotate(info, info->stack_b, "rb");
		}
		if (!is_sorted(info->stack_a, 1))
			swap(info, &(info->stack_a->list), "sa");
		last_pivot -= 2;
	}

	// sort_b
	last_pivot = sort_b(info, 0, pivot - 1);
	// b -> a
	while (last_pivot < pivot)
	{
		count = 2;
		while (count)
		{
			if (info->stack_a->list->val >= info->sorted_arr[last_pivot]
				&& info->stack_a->list->val <= info->sorted_arr[last_pivot + 1])
			{
				push(info, info->stack_a, info->stack_b, "pb");
				count--;
			}
			else
				rotate(info, info->stack_a, "ra");
		}
		if (!is_sorted(info->stack_b, 0))
			swap(info, &(info->stack_b->list), "sb");
		last_pivot += 2;
	}
	
	// 전부 a로
	while (info->stack_b->size)
		push(info, info->stack_b, info->stack_a, "pa");
}

int	sort_b(t_info *info, int left, int right)
{
	int		pivot;
	int		count;

	if (is_sorted(info->stack_b, 0))
		return (right + 2);
	if (right - left < 3)
	{
		sort_three(info, stack_b);
		return (right + 2);
	}
	pivot = (right - left) / 2;
	count = info->stack_b->size;
	while (count-- > 0)
	{
		if (info->stack_b->list->val > info->sorted_arr[pivot])
			push(info, info->stack_b, info->stack_a, "pa");
		else
			rotate(info, info->stack_b, "rb");
	}
	return (sort_b(info, left, (right - left) / 2 - 1));
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 2)
		return (0);
	set_info(&info, argc, argv);
	// print_stack(info.stack_a);
	quick_sort(info.sorted_arr, 0, info.size - 1);
	// for (int i = 0; i < info.count; i++)
	// 	printf("%d ", info.sorted_arr[i]);
	// puts("");

	sort(&info, 0, info.size - 1);
	// print_stack(info.stack_a);
	// print_stack(info.stack_b);

	print_cmds(info.cmds);

	return (0);
}
