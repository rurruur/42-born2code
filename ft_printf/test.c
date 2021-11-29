#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("%%\n===\n");
	ft_printf("%%");
	puts("\n============================");
	printf("character: %c\n===\n", '1');
	ft_printf("character: %c", '1');
	puts("\n============================");
	printf("string: %s\n===\n", "1234");
	ft_printf("string: %s", "1234");
}