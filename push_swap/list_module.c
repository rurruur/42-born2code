/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:26 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/01 15:00:36 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_list(Node *head)
{
	Node	*curr;
	Node	*remove;

	if (head)
	{
		curr = head->nextNode;
		free(head);
		while (curr != head)
		{
			remove = curr;
			curr = curr->nextNode;
			free(remove);
		}
	}
}

// test
void	print_list(Node *head)
{
	Node	*curr;

	curr = head;
	printf("head %p\ttail %p\n", head, head->prevNode);
	if (head)
	{
		printf("[%p] %d [%p]\n", head, head->data, head->nextNode);
		curr = head->nextNode;
		while (curr != head)
		{
			printf("[%p] %d [%p]\n", curr, curr->data, curr->nextNode);
			curr = curr->nextNode;
		}
	}
}

Node	*create_node(int num)
{
	Node	*node;

	node = (Node *)malloc(sizeof(Node));
	// 널가드?
	node->data = num;
	node->prevNode = 0;
	node->nextNode = 0;
	return (node);
}

void	append_node(Node **head, Node *node)
{
	Node	*tail;

	if (!(*head))
	{
		*head = node;
		return ;
	}
	tail = (*head)->prevNode;
	node->nextNode = *head;
	(*head)->prevNode = node;
	if (tail)
	{
		node->prevNode = tail;
		tail->nextNode = node;
	}
	else
	{
		(*head)->nextNode = node;
		node->prevNode = *head;
	}
}