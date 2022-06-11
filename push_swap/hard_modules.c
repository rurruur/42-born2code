/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_modules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:22:43 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/11 13:22:44 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_info *info)
{
	int		min;
	t_node	*curr;
	int		count;

	min = __INT_MAX__;
	count = info->stack_a->size;
	curr = info->stack_a->head;
	while (count--)
	{
		if (min > curr->val)
			min = curr->val;
		curr = curr->next;
	}
	return (min);
}

void	set_top_min(t_info *info)
{
	int		min_location;
	int		min;
	t_node	*curr;

	min = find_min(info);
	min_location = 0;
	curr = info->stack_a->head;
	while (min != curr->val)
	{
		curr = curr->next;
		min_location++;
	}
	if (min_location < info->stack_a->size / 2)
	{
		while (min_location-- > 0)
			rotate(info, info->stack_a, "ra");
	}
	else
	{
		while (min_location++ != info->stack_a->size)
			reverse_rotate(info, info->stack_a, "rra");
	}
}
