/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_module.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:31:32 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/10 17:02:21 by nakkim           ###   ########.fr       */
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
		stack->list->prev->next = newNode;
		stack->list->prev = newNode;
	}
	else
	{
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	stack->list = newNode;
	(stack->size)++;
}

t_node	*del_top(t_stack *stack)
{
	t_node	*remove;

	remove = stack->list;
	stack->list->next->prev = remove->prev;
	stack->list->prev->next = remove->next;
	stack->list = remove->next;
	if (stack->list == remove)
		stack->list = NULL;
	(stack->size)--;
	return (remove);
}

void	add_cmd(t_info *info, char *cmd)
{
	t_cmd	*new_cmd;
	t_cmd	*last;

	new_cmd = (t_cmd*)malloc(sizeof(t_cmd));
	new_cmd->name = cmd;
	new_cmd->next = NULL;
	if (info->cmds == NULL)
	{
		info->cmds = new_cmd;
		return ;
	}
	last = info->cmds;
	while (last->next != NULL)
		last = last->next;
	last->next = new_cmd;
}

void	push(t_info *info, t_stack *src, t_stack *dest, char *cmd)
{
	add_top(del_top(src), dest);
	add_cmd(info, cmd);
}

void	rotate(t_info *info, t_stack *target, char *cmd)
{
	target->list = target->list->next;
	add_cmd(info, cmd);
}