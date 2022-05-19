/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:20 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/19 19:40:48 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_info
{
	int		count;
	int		*stack;
	int		a;
	int		chunk;
}	t_info;

void	error(void);
int		is_num(char c);
void	set_nums(t_info info, int argc, char **argv);
int		get_num_count(int argc, char **argv);
void	set_info(t_info *info, int argc, char **argv);
void	swap(int *arr, int index1, int index2);
void	quick_sort(int *arr, int left, int right);
void	indexing(t_info *info);
void	rotate_b(t_info *info);
void	reverse_rotate_b(t_info *info);
void	push_b(t_info *info);
void	push_a(t_info *info);
void	rotate_a(t_info *info);
void	reverse_rotate_a(t_info *info);
void	swap_a(t_info *info);
void	set_top(t_info *info);
void	a_to_b(t_info *info);
void	b_to_a(t_info *info);
void	check_dup(t_info *info);

void	print_stack(t_info info);

#endif