/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:29:03 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 23:04:04 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	check_dup(t_info *info)
{
	t_node	*target;
	t_node	*comp;

	target = info->stack_a->head;
	while (target->next < info->stack_a->head)
	{
		comp = target->next;
		while (comp != info->stack_a->head)
		{
			if (target->val == comp->val)
				error();
			comp = comp->next;
		}
		target = target->next;
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
	curr = stack->head;
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
