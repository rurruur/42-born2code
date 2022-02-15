#include "quick_sort.h"

void	swap(t_stack *stack, char *method)
{
	t_node	*second;

	second = stack->head->next_node;
	stack->tail->next_node = second;
	second->next_node->prev_node = stack->head;
	second->prev_node = stack->tail;
	stack->head->next_node = second->next_node;
	second->next_node = stack->head;
	stack->head->prev_node = second;
	stack->head = second;
	write(1, method, 3);
}

void	rotate(t_stack *stack, char *method)
{
	stack->head = stack->head->next_node;
	stack->tail = stack->tail->next_node;
	write(1, method, 3);
}

void	reverse_rotate(t_stack *stack, char *method)
{
	stack->head = stack->head->prev_node;
	stack->tail = stack->tail->prev_node;
	write(1, method, 4);
}

void	push(t_stack *target, t_stack *dest, char *method)
{
	t_node	*popped;

	popped = pop(target);
	if (!dest->head)
	{
		dest->head = popped;
		dest->tail = popped;
		popped->next_node = popped;
		popped->prev_node = popped;
	}
	else {
		dest->tail->next_node = popped;
		dest->head->prev_node = popped;
		popped->prev_node = dest->tail;
		popped->next_node = dest->head;
		dest->head = popped;
	}
	write(1, method, 3);
}