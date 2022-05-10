/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:35:21 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/10 15:33:15 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*curr = stack->list;
	printf("[top] ");
	for (int i = 0; i < stack->size; i++)
	{
		printf("%d  ", curr->val);
		curr = curr->next;
	}
	puts("");
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 2)
		return (0);
	set_info(&info, argc, argv);
	print_stack(info.stack_a);
	quick_sort(info.sorted_arr, 0, info.count - 1);
	for (int i = 0; i < info.count; i++)
		printf("%d ", info.sorted_arr[i]);
	puts("");
	return (0);
}
