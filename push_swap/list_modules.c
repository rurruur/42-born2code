/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:05:12 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/11 13:25:11 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_top(t_stack *stack, t_node *new_node)
{
	if (stack->head == NULL)
	{
		stack->head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = stack->head;
		new_node->prev = stack->head->prev;
		stack->head->prev->next = new_node;
		stack->head->prev = new_node;
	}
	stack->head = new_node;
	(stack->size)++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*remove;

	remove = stack->head;
	stack->head->next->prev = remove->prev;
	stack->head->prev->next = remove->next;
	stack->head = remove->next;
	if (stack->head == remove)
		stack->head = NULL;
	(stack->size)--;
	return (remove);
}

void	add_cmd(t_info *info, t_cmd *new_cmd)
{
	if (info->cmds == NULL)
		info->cmds = new_cmd;
	else
	{
		new_cmd->next = info->cmds;
		new_cmd->prev = info->cmds->prev;
		info->cmds->prev->next = new_cmd;
		info->cmds->prev = new_cmd;
	}
}
