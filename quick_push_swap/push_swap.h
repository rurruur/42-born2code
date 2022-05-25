/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:11:20 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 17:07:36 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node*	list;
	int		size;
}	t_stack;

typedef struct s_cmd
{
	char*			name;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_info
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_arr;
	t_cmd	*cmds;
}	t_info;

int		is_num(char c);
int		get_num_size(int argc, char **argv);
void	set_nums(int *nums, int argc, char **argv);
void	set_info(t_info *info, int argc, char **argv);
t_stack	*create_stack(void);
t_node	*create_node(int val);
void	add_top(t_node *newNode, t_stack *stack);
t_node	*del_top(t_stack *stack);
void	quick_sort(int *arr, int left, int right);
void	push(t_info *info, t_stack *src, t_stack *dest, char *cmd);
void	rotate(t_info *info, t_stack *target, char *cmd);
void	swap(t_info *info, t_node **target, char *cmd);
int		sort_a(t_info *info, int left, int right);
int		sort_b(t_info *info, int left, int right);

void	print_stack(t_stack *stack);

#endif