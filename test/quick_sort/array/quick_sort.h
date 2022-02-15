#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

void	print_stack(int	*stack, int argc);
int	*create_stack(int argc, char **argv);
void	sort_stack(int *stack, int left, int right);
int	partition(int *stack, int left, int right);
void	swap_node(int *stack, int left, int right);

#endif