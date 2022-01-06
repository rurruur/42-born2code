#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	void	*a;
	char	c;

	a = "1234";
	c = (char)222;
	printf("printf: %d\n", printf("%%%%\n===\n"));
	printf("ft: %d\n", ft_printf("%%%%\n===\n"));
	ft_printf("\n============================\n");
	printf("%d\n", printf("character: %c %c %c\n===\n", '1', 'z', c));
	printf("%d\n", ft_printf("character: %c %c %c\n===\n", '1', 'z', c));
	puts("\n============================");
	printf("%d\n", printf("string: %s\n===\n", "1234"));
	printf("%d\n", ft_printf("string: %s\n===\n", "1234"));
	puts("\n============================");
	printf("%d\n", printf("num: %d %d %d\n===\n", 2147483647, -2147483647, 1000));
	printf("%d\n", ft_printf("num: %d %d %d\n===\n", 2147483647, -2147483647, 1000));
	puts("\n============================");
	printf("num(i): %i %i %i\n===\n", 2147483647, -2147483647, 0);
	ft_printf("num(i): %i %i %i", 2147483647, -2147483647, 0);
	puts("\n============================");
	printf("num(u): %u %u %u\n===\n", 1234, -2147483647, 0);
	ft_printf("num(u): %u %u %u", 1234, -2147483647, 0);
	puts("\n============================");
	printf("hex: %x\n===\n", 1234);
	ft_printf("hex: %x", 1234);
	puts("\n============================");
	printf("hex: %X\n===\n", 1234);
	ft_printf("hex: %X", 1234);
	puts("\n============================");
	printf("hex: %p\n===\n", a);
	ft_printf("hex: %p", a);
	printf("hex: %p\n===\n", NULL);
	ft_printf("hex: %p", NULL);
}