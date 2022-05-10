/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:31:32 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/10 13:42:22 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_top(t_node *newNode, t_stack *stack)
{
	if (stack->list != NULL)
	{
		newNode->next = stack->list;
		newNode->prev = stack->list->prev;
	}
	else
	{
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	stack->list = newNode;
	(stack->size)++;
}