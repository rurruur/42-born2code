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
	int	low;
	int	high;

	pivot = left;
	low = left + 1;
	high = right;
	while (low < high)
	{
		printf("start - low: %d\thigh: %d\n", low, high);
		while (low < right && stack[pivot] > stack[low])
			low++;
		while (high > left && stack[pivot] < stack[high])
			high--;
		printf("end - low: %d\thigh: %d\n", low, high);
		if (low < high)
			swap_node(stack, low, high);
		puts("");
		print_stack(stack, 5);
	}
	if (low > high)
		swap_node(stack, pivot, high);
	puts("");
	print_stack(stack, 5);
	getchar();
	return (high);
}

void	sort_stack(int *stack, int left, int right)
{
	int	pivot;

	puts("sort stack");
	printf("left: %d\tright: %d\n", left, right);
	getchar();
	if (left < right)
	{
		pivot = partition(stack, left, right);
		sort_stack(stack, left, pivot - 1);
		sort_stack(stack, pivot + 1, right);
	}
}

int	*create_stack(int argc, char **argv)
{
	int	*stack;
	int	index;

	index = -1;
	stack = (int *)malloc(sizeof(int) * argc);
	while (++index < argc)
		stack[index] = ft_atoi(argv[index + 1]);
	return (stack);
}

void	print_stack(int	*stack, int argc)
{
	int	index;

	index = -1;
	while (++index < argc)
		printf("[%d] %d\n", index, stack[index]);
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
	sort_stack(stack, 0, argc - 1);
	puts("===========");
	print_stack(stack, argc);

	free(stack);
	getchar();
	return (0);
}