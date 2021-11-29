#include "ft_printf.h"
#include "./libft/libft.h"

#include <stdio.h>

int	is_seosick(unsigned char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		index;
	char	current_c;

	index = -1;
	va_start(ap, s);
	while (s[++index])
	{
		if (s[index] != '%')
		{
			write(1, &(s[index]), 1);
			continue;
		}
		//if (!s[index + 1] || !is_seosick(s[index + 1]))
			// Err!
		// handle seosick
		index++;
		current_c = s[index];
		if (current_c == '%')
			write(1, "%", 1);
		else if (current_c == 'c')
		{
			char	ch;
			ch = va_arg(ap, int);
			write(1, &ch, 1);
		}
		if (current_c == 's')
		{
			char	*ptr;
			ptr = va_arg(ap, char *);
			write(1, ptr, ft_strlen(ptr));
		}
	}
	return (1);
}