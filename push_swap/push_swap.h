/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:32:07 by nakkim            #+#    #+#             */
/*   Updated: 2022/02/01 14:35:28 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
// 지워
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *prevNode;
	struct Node *nextNode;
} Node;

void	print_error(void);
void	set_stack(Node **, int, char **);
void	append_node(Node **, Node *);
Node	*create_node(int);
void	print_list(Node *);
void	destroy_list(Node *);

#endif