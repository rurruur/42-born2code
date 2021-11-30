#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("%%%%\n===\n");
	ft_printf("%%%%");
	ft_printf("\n============================\n");
	printf("character: %c %c\n===\n", '1', 'z');
	ft_printf("character: %c %c", '1', 'z');
	puts("\n============================");
	printf("string: %s\n===\n", "1234");
	ft_printf("string: %s", "1234");
	puts("\n============================");
	printf("num: %d %d %d\n===\n", 2147483647, -123, 0);
	ft_printf("num: %d %d %d", 2147483647, -123, 0);
	puts("\n============================");
	printf("num(i): %i %i %i\n===\n", 2147483647, -123, 0);
	ft_printf("num(i): %i %i %i", 2147483647, -123, 0);
	puts("\n============================");
	printf("num(u): %u %u %u\n===\n", 1234, -123, 0);
	ft_printf("num(u): %u %u %u", 1234, -123, 0);
	puts("\n============================");
	printf("hex: %x\n===\n", 1234);
	ft_printf("hex: %x", 1234);
	puts("\n============================");
	printf("hex: %X\n===\n", 1234);
	ft_printf("hex: %X", 1234);
}