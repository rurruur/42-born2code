/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:32:22 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/01 14:32:23 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// write, read, malloc, free, exit

void	set_stack(Node **head, int argc, char **argv)
{
	int	index;
	int	value_index;

	index = 0;
	while (++index < argc)
	{
		value_index = -1;
		while (argv[index][++value_index])
		{
			// 매개변수를 숫자인지 확인
			if (!ft_isdigit(argv[index][value_index]))
				print_error();
		}
		// 노드 생성 후 연결
		append_node(head, create_node(ft_atoi(argv[index])));
	}
}

void	print_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	Node	*a_head;

	a_head = 0;
	if (argc == 1)
		print_error();
	set_stack(&a_head, argc, argv);
	
	print_list(a_head);
	destroy_list(a_head);

	return (0);
}