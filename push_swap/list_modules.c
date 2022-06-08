/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:05:12 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 23:04:34 by nakkim           ###   ########.fr       */
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

t_cmd	*create_cmd(char *cmd)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	new_cmd->name = cmd;
	new_cmd->next = new_cmd;
	new_cmd->prev = new_cmd;
	return (new_cmd);
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

void	push(t_info *info, t_stack *src, t_stack *dest, char *cmd)
{
	add_top(dest, pop(src));
	add_cmd(info, create_cmd(cmd));
}

void	rotate(t_info *info, t_stack *target, char *cmd)
{
	target->head = target->head->next;
	add_cmd(info, create_cmd(cmd));
}

void	reverse_rotate(t_info *info, t_stack *target, char *cmd)
{
	target->head = target->head->prev;
	add_cmd(info, create_cmd(cmd));
}

void	swap(t_info *info, t_stack *target, char *cmd)
{
	t_node	*head_next;

	head_next = target->head->next;
	target->head->prev->next = head_next;
	head_next->prev = target->head->prev;
	target->head->next = head_next->next;
	head_next->next->prev = target->head;
	head_next->next = target->head;
	target->head->prev = head_next;
	target->head = head_next;
	add_cmd(info, create_cmd(cmd));
}
