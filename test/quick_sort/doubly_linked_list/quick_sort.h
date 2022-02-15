#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct Node {
	int			data;
	struct Node	*prev_node;
	struct Node	*next_node;
}	t_node;

typedef struct Stack {
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	print_stack(t_stack *stack);
void	swap(t_stack *stack, char *method);
void	push(t_stack *target, t_stack *dest, char *method);
void	rotate(t_stack *stack, char *method);
void	reverse_rotate(t_stack *stack, char *method);
int		set_head(t_stack *stack, t_node *target, char *method, void(*fp)(t_stack*, char*));
t_node	*pop(t_stack *stack);

#endif