#include "push_swap.h"

int	is_prev(t_node *head, t_node *base, t_node *target)
{
	if (base == head)
		return (0);
	if (base == head->prev_node && base != target)
		return (1);
	while (base->next_node != head && base != target)
	{
		if (base->next_node == target)
			return (0);
		base = base->next_node;
	}
	return (1);
}