/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:32:22 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/25 13:39:37 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// write, read, malloc, free, exit

long long	ft_atol(char *ptr)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -sign;
		ptr++;
	}
	while (ft_isdigit(*ptr))
		num = num * 10 + *ptr++ - '0';
	return (num * sign);
}

void	set_stack(t_node **head, int argc, char **argv)
{
	int			index;
	int			value_index;
	long long	num;

	index = 0;
	while (++index < argc)
	{
		value_index = -1;
		while (argv[index][++value_index])
		{
			if (argv[index][value_index] == '-'
				|| argv[index][value_index] == '+')
				continue ;
			// 매개변수를 숫자인지 확인
			if (!ft_isdigit(argv[index][value_index]))
				print_error();
		}
		// 노드 생성 후 연결
		num = ft_atol(argv[index]);
		if (num > 2147483647 || num < -2147483648)
			print_error();
		append_node(head, create_node(num));
	}
}

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_node	*a_head;
	t_node	*b_head;

	a_head = 0;
	b_head = 0;
	if (argc == 1)
		print_error();
	set_stack(&a_head, argc, argv);
	puts("--a--");
	print_list(a_head);
	puts("--b--");
	print_list(b_head);

	sort_list(&a_head, a_head->next_node, a_head->prev_node, &b_head);
	puts("--a--");
	print_list(a_head);
	puts("--b--");
	print_list(b_head);
	destroy_list(a_head);
	destroy_list(b_head);
	return (0);
}
