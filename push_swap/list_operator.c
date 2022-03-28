/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:15:42 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/25 13:03:59 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **head, char *method)
{
	t_node	*tail;
	t_node	*second_node;

	if (!(*head))
		return ;
	tail = (*head)->prev_node;
	second_node = (*head)->next_node;
	tail->next_node = second_node;
	(*head)->next_node = second_node->next_node;
	(*head)->prev_node = second_node;
	second_node->prev_node = tail;
	second_node->next_node = *head;
	*head = second_node;
	write(1, method, 3);
}

void	push(t_node **head, t_node **dest_head, char *method)
{
	t_node	*target;

	if (!(*head))
		return ;
	target = *head;
	if (*head == (*head)->next_node)
		*head = 0;
	else
	{
		(*head)->prev_node->next_node = (*head)->next_node;
		(*head)->next_node->prev_node = (*head)->prev_node;
		*head = (*head)->next_node;
	}
	add_top(dest_head, target);
	write(1, method, 3);
}

void	rotate(t_node **head, char *method)
{
	if (!(*head))
		return ;
	*head = (*head)->next_node;
	write(1, method, 3);
}

void	reverse_rotate(t_node **head, char *method)
{
	if (!(*head))
		return ;
	*head = (*head)->prev_node;
	write(1, method, 4);
}
