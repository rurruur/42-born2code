/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:44:02 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/19 19:41:40 by nakkim           ###   ########.fr       */
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

void	rotate_a(t_info *info)
{
	int	index;
	int	tmp;

	index = info->a;
	tmp = info->stack[info->a];
	while (index > 0)
	{
		info->stack[index] = info->stack[index - 1];
		index--;
	}
	info->stack[0] = tmp;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_info *info)
{
	int	index;
	int	tmp;

	index = 0;
	tmp = info->stack[index];
	while (index < info->a)
	{
		info->stack[index] = info->stack[index + 1];
		index++;
	}
	info->stack[info->a] = tmp;
	write(1, "rra\n", 4);
}

void	push_b(t_info *info)
{
	(info->a)--;
	write(1, "pb\n", 3);
}

void	push_a(t_info *info)
{
	(info->a)++;
	write(1, "pa\n", 3);
}

void	swap_a(t_info *info)
{
	int	tmp;

	tmp = info->stack[info->a];
	info->stack[info->a] = info->stack[info->a - 1];
	info->stack[info->a - 1] = tmp;
	write(1, "sa\n", 3);
}