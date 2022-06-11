/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:13:04 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/11 13:24:59 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_indexing(t_info *info)
{
	int		i;
	t_node	*curr;

	curr = info->stack_a->head;
	i = -1;
	while (++i < info->size)
		if (info->sorted_arr[i] == curr->val)
			break ;
	curr->val = i;
	curr = curr->next;
	while (curr != info->stack_a->head)
	{
		i = -1;
		while (++i < info->size)
			if (info->sorted_arr[i] == curr->val)
				break ;
		curr->val = i;
		curr = curr->next;
	}
}

void	set_info(t_info *info, int argc, char **argv)
{
	int	index;

	info->size = get_list_size(argc, argv);
	info->sorted_arr = (int *)malloc(sizeof(int) * info->size);
	if (!(info->sorted_arr))
		exit(1);
	set_nums(*info, argc, argv);
	info->stack_a = create_stack();
	info->stack_b = create_stack();
	info->cmds = NULL;
	index = 0;
	while (index < info->size)
		add_top(info->stack_a, create_node(info->sorted_arr[index++]));
}

int	get_list_size(int argc, char **argv)
{
	int		size;
	int		i;

	size = 0;
	while (--argc > 0)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (argv[argc][i] == '-' || argv[argc][i] == '+')
				i++;
			if (is_num(argv[argc][i]))
			{
				size++;
				while (is_num(argv[argc][i]))
					i++;
			}
			else if (argv[argc][i] == ' ')
				i++;
			else
				error();
		}
	}
	return (size);
}

int	my_atoi(char *ptr, int *i)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (ptr[*i] == ' ' || (ptr[*i] >= 9 && ptr[*i] <= 13))
		(*i)++;
	if (ptr[*i] == '-' || ptr[*i] == '+')
	{
		if (ptr[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	while (ptr[*i] >= '0' && ptr[*i] <= '9')
	{
		num = num * 10 + ptr[*i] - '0';
		(*i)++;
	}
	if (num * sign > __INT_MAX__ || num * sign < INT_MIN)
		error();
	return (num * sign);
}

void	set_nums(t_info info, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			info.sorted_arr[info.size - 1] = my_atoi(argv[i], &j);
			(info.size)--;
		}
		i++;
	}
}
