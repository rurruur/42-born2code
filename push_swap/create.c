/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:25:22 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/11 13:25:22 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = 0;
	stack->head = NULL;
	return (stack);
}

t_cmd	*create_cmd(char *cmd)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	new_cmd->name = cmd;
	new_cmd->next = new_cmd;
	new_cmd->prev = new_cmd;
	return (new_cmd);
}
