/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:13:04 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 17:07:54 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_info(t_info *info, int argc, char **argv)
{
	int	index;

	info->size = get_num_size(argc, argv);
	info->sorted_arr = (int*)malloc(sizeof(int) * info->size);
	if (!(info->sorted_arr))
		exit(1);
	set_nums(info->sorted_arr, argc, argv);
	info->stack_a = create_stack();
	info->stack_b = create_stack();
	info->cmds = NULL;
	index = info->size;
	while (index--)
		add_top(create_node(info->sorted_arr[index]), info->stack_a);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->size = 0;
	stack->list = NULL;
	return (stack);
}

int	get_num_size(int argc, char **argv)
{
	int		size;
	int		index;

	size = 0;
	while (--argc > 0)
	{
		index = 0;
		while (argv[argc][index])
		{
			if (is_num(argv[argc][index]))
			{
				size++;
				while (is_num(argv[argc][index]))
					index++;
			}
			else
				index++;
		}
	}
	return (size);
}

void	set_nums(int *nums, int argc, char **argv)
{
	int		index;
	int		flag;

	index = 1;
	flag = 1;
	while (index < argc)
	{
		while (*(argv[index]))
		{
			if (*(argv[index]) == '-' || *(argv[index]) == '+')
				flag = 44 - *(argv[index]);
			if (is_num(*(argv[index])))
			{
				*nums = 0;
				while (is_num(*(argv[index])))
				{
					*nums = *nums * 10 + *(argv[index]) - '0';
					(argv[index])++;
				}
				*nums *= flag;
				flag = 1;
				nums++;
			}
			else
				(argv[index])++;
		}
		index++;
	}
}
