/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:13:04 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/19 20:22:51 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

void	set_info(t_info *info, int argc, char **argv)
{
	int	index;

	info->count = get_num_count(argc, argv);
	info->stack = (int *)malloc(sizeof(int) * info->count);
	if (!(info->stack))
		error();
	set_nums(*info, argc, argv);
	info->a = info->count - 1;
	info->chunk = 0.000000053 * (info->count * info->count) +  0.03 * info->count + 14.5;
	index = info->count;
}

int	get_num_count(int argc, char **argv)
{
	int		count;
	int		index;

	count = 0;
	while (--argc > 0)
	{
		index = 0;
		while (argv[argc][index])
		{
			while (argv[argc][index] == '-' || argv[argc][index] == '+')
				index++;
			if (is_num(argv[argc][index]))
			{
				count++;
				while (is_num(argv[argc][index]))
					index++;
			}
			else if (argv[argc][index] == ' ')
				index++;
			else
				error();
		}
	}
	return (count);
}

void	set_nums(t_info info, int argc, char **argv)
{
	int		index;
	int		flag;
	long	num;
	
	index = 1;
	flag = 1;
	while (index < argc)
	{
		num = 0;
		while (*(argv[index]))
		{
			if (*(argv[index]) == '-' || *(argv[index]) == '+')
				flag = 44 - *(argv[index]);
			if (is_num(*(argv[index])))
			{
				while (is_num(*(argv[index])))
				{
					num = num * 10 + *(argv[index]) - '0';
					(argv[index])++;
				}
				if (num * flag > 2147483647 || num * flag < -2147483648)
					error();
				info.stack[info.count - 1] = num * flag;
				flag = 1;
				(info.count)--;
			}
			else
				(argv[index])++;
		}
		index++;
	}
}
