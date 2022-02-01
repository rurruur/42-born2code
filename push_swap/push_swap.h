/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:32:07 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/01 16:02:36 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
// 지워
# include <stdio.h>

typedef struct Node {
	int			data;
	struct Node	*prev_node;
	struct Node	*next_node;
}	t_node;

void		print_error(void);
void		set_stack(t_node **head, int argc, char **argv);
void		append_node(t_node **head, t_node *node);
t_node		*create_node(int num);
void		print_list(t_node *head);
void		destroy_list(t_node *head);
long long	ft_atol(char *ptr);
void		swap(t_node **head);
void		push(t_node **head, t_node **dest_head);
void		add_top(t_node **head, t_node *node);
void		rotate(t_node **head);
void		reverse_rotate(t_node **head);

#endif