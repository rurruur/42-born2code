/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:20 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 23:03:41 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

# define INT_MIN -2147483648

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node*	head;
	int		size;
}	t_stack;

typedef struct s_cmd
{
	char*			name;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_info
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_arr;
	t_cmd	*cmds;
}	t_info;

void	error(void);
void	check_dup(t_info *info);
int		is_num(char c);
int		is_sorted(t_stack *stack, int flag);
void	add_top(t_stack *stack, t_node *new_node);
t_node	*create_node(int val);
t_stack	*create_stack(void);
t_node	*pop(t_stack *stack);
t_cmd*	create_cmd(char *cmd);
void	add_cmd(t_info *info, t_cmd *new_cmd);
void	push(t_info *info, t_stack *src, t_stack *dest, char *cmd);
void	rotate(t_info *info, t_stack *target, char *cmd);
void	reverse_rotate(t_info *info, t_stack *target, char *cmd);
void	swap(t_info *info, t_stack *target, char *cmd);
void	quick_sort(int *arr, int left, int right);
void	set_nums(t_info info, int argc, char **argv);
int		my_atoi(char *ptr, int *i);
int		get_list_size(int argc, char **argv);
void	set_info(t_info *info, int argc, char **argv);
void	hard_sort(t_info *info);
void	check_dup(t_info *info);
void	process_indexing(t_info *info);
void	sort(t_info *info);

#endif