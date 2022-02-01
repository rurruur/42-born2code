/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:26 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/01 15:39:44 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_list(t_node *head)
{
	t_node	*curr;
	t_node	*remove;

	if (head)
	{
		curr = head->next_node;
		free(head);
		while (curr != head)
		{
			remove = curr;
			curr = curr->next_node;
			free(remove);
		}
	}
}

// test
void	print_list(t_node *head)
{
	t_node	*curr;

	curr = head;
	printf("head %p\ttail %p\n", head, head->prev_node);
	if (head)
	{
		printf("[%p] %d [%p]\n", head, head->data, head->next_node);
		curr = head->next_node;
		while (curr != head)
		{
			printf("[%p] %d [%p]\n", curr, curr->data, curr->next_node);
			curr = curr->next_node;
		}
	}
}

t_node	*create_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	// 널가드?
	node->data = num;
	node->prev_node = 0;
	node->next_node = 0;
	return (node);
}

void	append_node(t_node **head, t_node *node)
{
	t_node	*tail;

	if (!(*head))
	{
		*head = node;
		(*head)->prev_node = node;
		(*head)->next_node = node;
		return ;
	}
	tail = (*head)->prev_node;
	node->next_node = *head;
	(*head)->prev_node = node;
	node->prev_node = tail;
	tail->next_node = node;
}
