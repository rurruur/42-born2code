/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:40:49 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/11 13:22:29 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_info *info)
{
	int	top;
	int	mid;
	int	bottom;

	top = info->stack_a->head->val;
	mid = info->stack_a->head->next->val;
	bottom = info->stack_a->head->prev->val;
	if (top < mid && top < bottom && mid > bottom)
	{
		reverse_rotate(info, info->stack_a, "rra");
		swap(info, info->stack_a, "sa");
	}
	else if (((top > mid && top < bottom) || (top < mid && top > bottom))
		&& (mid < bottom))
		swap(info, info->stack_a, "sa");
	else if (((top > mid && top < bottom) || (top < mid && top > bottom))
		&& (mid >= bottom))
		reverse_rotate(info, info->stack_a, "rra");
	else if (top > mid && top > bottom && mid < bottom)
		rotate(info, info->stack_a, "ra");
	else if (top > mid && top > bottom && mid > bottom)
	{
		swap(info, info->stack_a, "sa");
		reverse_rotate(info, info->stack_a, "rra");
	}
}

void	sort_4(t_info *info)
{
	set_top_min(info);
	push(info, info->stack_a, info->stack_b, "pb");
	sort_3(info);
	push(info, info->stack_b, info->stack_a, "pa");
}

void	sort_5(t_info *info)
{
	set_top_min(info);
	push(info, info->stack_a, info->stack_b, "pb");
	set_top_min(info);
	push(info, info->stack_a, info->stack_b, "pb");
	sort_3(info);
	push(info, info->stack_b, info->stack_a, "pa");
	push(info, info->stack_b, info->stack_a, "pa");
}

void	hard_sort(t_info *info)
{
	if (info->stack_a->size == 2)
		rotate(info, info->stack_a, "ra");
	else if (info->stack_a->size == 3)
		sort_3(info);
	else if (info->stack_a->size == 4)
		sort_4(info);
	else if (info->stack_a->size == 5)
		sort_5(info);
}
