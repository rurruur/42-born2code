/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:43:37 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/01 17:10:35 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *head)
{
	t_node  *curr;

	if (!head)
		return (1);
	if (head->prev_node->data < head->data
		|| head->next_node->data < head->data)
		return (0);
	curr = head->next_node;
	while (curr != head)
	{
		if (curr->prev_node->data < curr->data
			|| curr->next_node->data < curr->data)
			return (0);
		curr = curr->next_node;
	}
	return (1);
}

void	sort_list(t_node **a_head, t_node **b_head)
{
	while (!is_sorted(*a_head) || !(*b_head))
	{
	}
}
