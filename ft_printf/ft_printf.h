#ifndef F_PRINTF_H
#define F_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

int     ft_printf(const char *s, ...);
char    *ft_ltoa(int n);
char    *print_hex(int n, char c);

#endif