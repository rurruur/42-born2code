#include "quick_sort.h"

void	swap_node(int *stack, int left, int right)
{
	int	tmp;

	tmp = stack[left];
	stack[left] = stack[right];
	stack[right] = tmp;
}

int	partition(int *stack, int left, int right)
{
	int	pivot;

	pivot = left;
	left--;
	printf("left: %d\tright: %d\n", left, right);
	while (left > right)
	{
		while (left > right && stack[pivot] > stack[left])
			left--;
		while (right < pivot && stack[pivot] < stack[right])
			right++;
		if (left > right)
			swap_node(stack, left, right);
		puts("");
		printf("left: %d\tright: %d\n", left, right);
		print_stack(stack, 7);
	}
	swap_node(stack, pivot, right);
	puts("");
	printf("left: %d\tright: %d\n", left, right);
	print_stack(stack, 7);
	return (right);
}

void	sort_stack(int *stack, int left, int right)
{
	int	pivot;

	puts("sort stack");
	printf("left: %d\tright: %d\n", left, right);
	getchar();
	if (left > right)
	{
		pivot = partition(stack, left, right);
		sort_stack(stack, left, pivot + 1);
		sort_stack(stack, pivot - 1, right);
	}
}

int	*create_stack(int argc, char **argv)
{
	int	*stack;
	int	index;

	index = 0;
	stack = (int *)malloc(sizeof(int) * argc);
	while (--argc >= 0)
		stack[argc] = ft_atoi(argv[++index]);
	return (stack);
}

void	print_stack(int	*stack, int argc)
{
	while (--argc >= 0)
		printf("[%d] %d\n", argc, stack[argc]);
}

// 인덱스 0이 bottom
int	main(int argc, char **argv)
{
	int	*stack;

	argc--;
	if (argc == 0)
		return (0);
	stack = create_stack(argc, argv);
	print_stack(stack, argc);
	sort_stack(stack, argc - 1, 0);
	puts("===========");
	print_stack(stack, argc);

	free(stack);
	getchar();
	return (0);
}