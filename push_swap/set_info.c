/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:13:04 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/23 16:36:18 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

void	set_info(t_info *info, int argc, char **argv)
{
	info->count = get_num_count(argc, argv);
	info->stack = (int *)malloc(sizeof(int) * info->count);
	if (!(info->stack))
		error();
	set_nums(*info, argc, argv);
	info->a = info->count - 1;
	info->chunk = 0.000000053 * (info->count * info->count)
		+ 0.03 * info->count + 14.5;
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
	if (num * sign > 2147483647 || num * sign < -2147483648)
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
			if (is_num(argv[i][j]) || argv[i][j] == ' '
				|| argv[i][j] == '-' || argv[i][j] == '+')
			{
				info.stack[info.count - 1] = my_atoi(argv[i], &j);
				(info.count)--;
			}
			else
				error();
		}
		i++;
	}
}
