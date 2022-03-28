/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:43:37 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/25 13:40:57 by nakkim           ###   ########.fr       */
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
	while (curr->next_node != head)
	{
		if (curr->prev_node->data < curr->data
			|| curr->next_node->data < curr->data)
			return (0);
		curr = curr->next_node;
	}
	return (1);
}

t_node	*quick_sort(t_node **a_head, t_node *L, t_node *R, t_node **b_head)
{
	t_node	*left;
	t_node	*right;
	t_node	*pivot;

	pivot = *a_head;
	left = L;
	right = R;
	printf("%p\n", b_head);
	printf("quick sort --- L: %d, R: %d\n", L->data, R->data);
	while (!is_prev(*a_head, left, right))
	{
		getchar();
		while (left->data < pivot->data)
			left = left->next_node;
		while (right->data > pivot->data)
			right = right->prev_node;
		printf("left: %d\tright:%d\n", left->data, right->data);
		printf("is prev? %d\n", is_prev(*a_head, left, right));
		if (!is_prev(*a_head, left, right))
		{
			t_node *tmp2 = left;
			int tmp = left->data;
			left->data = right->data;
			right->data = tmp;
			left = right;
			right = tmp2;
		}
		print_list(*a_head);
	}
	t_node *tmp2 = pivot;
	int tmp = pivot->data;
	pivot->data = right->data;
	right->data = tmp;
	pivot = right;
	right = tmp2;
	return right;
}

void	sort_list(t_node **a_head, t_node *L, t_node *R, t_node **b_head)
{
	if (!is_prev(*a_head, L, R))
	{
		t_node *pivot = quick_sort(a_head, L, R, b_head);
		quick_sort(a_head, L, pivot->prev_node, b_head);
		quick_sort(a_head, pivot->next_node, R, b_head);

	}
}
