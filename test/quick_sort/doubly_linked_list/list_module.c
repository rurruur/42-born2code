#include "quick_sort.h"

t_node	*pop(t_stack *stack)
{
	t_node	*popped;
	t_node	*second;

	popped = stack->head;
	if (stack->head == stack->tail)
	{
		stack->head = 0;
		stack->tail = 0;
		return (popped);
	}
	second = stack->head->next_node;
	stack->tail->next_node = second;
	second->prev_node = stack->tail;
	stack->head = second;
	return (popped);
}

int	set_head(t_stack *stack, t_node *target, char *method, void(*fp)(t_stack*, char*))
{
	int	count;

	count = 0;
	while (stack->head != target)
	{
		fp(stack, method);
		count++;
	}
	return (count);
}