/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:24:00 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/11 13:24:01 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
