/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:40:14 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/23 15:40:17 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_info *info)
{
	int	index;
	int	tmp;

	index = info->a + 1;
	tmp = info->stack[index];
	while (index < info->count - 1)
	{
		info->stack[index] = info->stack[index + 1];
		index++;
	}
	info->stack[index] = tmp;
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_info *info)
{
	int	index;
	int	tmp;

	index = info->count - 1;
	tmp = info->stack[index];
	while (index > info->a + 1)
	{
		info->stack[index] = info->stack[index - 1];
		index--;
	}
	info->stack[info->a + 1] = tmp;
	write(1, "rrb\n", 4);
}

void	push_b(t_info *info)
{
	(info->a)--;
	write(1, "pb\n", 3);
}
