#include "quick_sort.h"



t_node	*create_node(int num)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->data = num;
	node->next_node = 0;
	node->prev_node = 0;
	return (node);
}

void	append_node(t_stack *stack, t_node *node)
{
	// node null guard
	if (!(stack->head))
	{
		stack->head = node;
		stack->tail = node;
		node->next_node = node;
		node->prev_node = node;
		return ;
	}
	stack->tail->next_node = node;
	node->prev_node = stack->tail;
	stack->tail = node;
	stack->head->prev_node = node;
	node->next_node = stack->head;
}

void	create_stack(t_stack *stack, int argc, char **argv)
{
	int	index;

	index = 0;
	while (++index < argc)
		append_node(stack, create_node(ft_atoi(argv[index])));
}

void	print_stack(t_stack *stack)
{
	t_node	*curr;

	curr = stack->head;
	printf("head: %p\ttail: %p\n", stack->head, stack->tail);
	if (!curr)
		return ;
	printf("[%p] %p - %d [%p]\n", curr->prev_node, curr, curr->data, curr->next_node);
	curr = curr->next_node;
	while (curr != stack->head)
	{
		printf("[%p] %p - %d [%p]\n", curr->prev_node, curr, curr->data, curr->next_node);
		curr = curr->next_node;
	}
}

void	destroy_stack(t_stack *stack)
{
	t_node	*remove;
	t_node	*curr;

	remove = stack->head;
	if (!remove)
		return ;
	curr = stack->head->next_node;
	free(remove);
	while (curr != stack->head)
	{
		remove = curr;
		curr = curr->next_node;
		free(remove);
	}
	free(stack);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = 0;
	stack->tail = 0;
	return (stack);
}

int	is_prev_node(t_stack *a, t_node *left, t_node *right)
{
	if (left == a->head)
	{
		if (left == right)
			return (0);
		left = left->next_node;
	}
	while (left != a->head)
	{
		if (left == right)
			return (-1);
		left = left->next_node;
	}
	return (1);
}


void	swap_node(t_stack *a, t_stack *b, t_node *left, t_node *right)
{
	int	count_left;
	int	count_head;

	if (right == left->next_node)
	{
		count_head = set_head(a, left, "ra\n", rotate);
		swap(a, "sa\n");
		while(count_head-- > 0)
			reverse_rotate(a, "rra\n");
		return ;
	}
	else if (right == left->prev_node)
	{
		// 이런 경우가 있나?
		count_head = set_head(a, right, "ra\n", rotate);
		swap(a, "sa\n");
		while(count_head-- > 0)
			reverse_rotate(a, "rra\n");
		return ;
	}
	count_head = set_head(a, left, "ra\n", rotate);
	push(a, b, "pb\n");
	count_left = set_head(a, right, "rra\n", reverse_rotate);
	push(a, b, "pb\n");
	set_head(b, left, "rb\n", rotate);
	push(b, a, "pa\n");
	while (count_left-- > 0)
		rotate(a, "ra\n");
	push(b, a, "pa\n");
	while (count_head-- > 0)
		reverse_rotate(a, "rra\n");
}

// 3 2 4(left) 5 1(right) 6
// 3 2 1(left) 5 4(right) 6
// 3 2 1(right) 5(left) 4 6
// 1 2 3(pivot) 5 4 6
t_node	*partition(t_stack *a, t_stack *b, t_node *left, t_node *right)
{
	t_node	*pivot;
	t_node	*tmp;

	pivot = left;
	left = left->next_node;
	while (is_prev_node(a, left, right) < 0)
	{
		puts("partition");
		while (pivot->data > left->data)
			left = left->next_node;
		while (pivot->data < right->data)
			right = right->prev_node;
		printf("left: %d\tright: %d\n", left->data, right->data);
		if (is_prev_node(a, left, right) < 0)
		{
			swap_node(a, b, left, right);
			// tmp = right;
			// right = left;
			// left = tmp;
		}
		printf("left: %d\tright: %d\n", left->data, right->data);
	}
	swap_node(a, b, pivot, right);
	print_stack(a);
	return (pivot);
}

void	sort_stack(t_stack *a, t_stack *b, t_node *left, t_node *right)
{
	t_node	*index;

	if (is_prev_node(a, left, right) < 0)
	{
		puts("sort stack");
		index = partition(a, b, left, right);
		printf("index: %p %d\n", index, index->data);
		printf("left: %d\tright: %d\n", left->data, right->data);
		getchar();
		sort_stack(a, b, left, index->prev_node);
		sort_stack(a, b, index->next_node, right);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = init_stack();
	b_stack = init_stack();
	if (argc == 1)
		return (0);
	create_stack(a_stack, argc, argv);
	print_stack(a_stack);
	print_stack(b_stack);

	sort_stack(a_stack, b_stack, a_stack->head, a_stack->tail);
	// swap_node(a_stack, b_stack, a_stack->head->next_node->next_node, a_stack->tail->prev_node);
	// swap_node(a_stack, b_stack, a_stack->head, a_stack->head->next_node);
	print_stack(a_stack);
	print_stack(b_stack);
	destroy_stack(a_stack);
	destroy_stack(b_stack);
	while (1) {;}
	return (0);
}