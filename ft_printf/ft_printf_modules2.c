#include "ft_printf.h"

int handle_c(va_list ap)
{
	char	ch;

	ch = va_arg(ap, int);
	write(1, &ch, 1);
    return (1);
}

int handle_d_i(va_list ap)
{
    int     len;
	int		num;
	char    *str;

	num = va_arg(ap, int);
	str = ft_itoa(num);
    len = ft_strlen(str);
	write(1, str, len);
	free(str);
    return (len);
}

int handle_s(va_list ap)
{
    int     len;
	char	*str;

	str = va_arg(ap, char *);
    len = ft_strlen(str);
	write(1, str, len);
    return (len);
}

int handle_u(va_list ap)
{
    int             len;
	unsigned int	num;
	char	        *str;

    num = va_arg(ap, unsigned int);
    str = ft_ltoa(num);
    len =ft_strlen(str);
	write(1, str, len);
	free(str);
    return (len);
}

int handle_x_X(va_list ap, char ch)
{
	unsigned int	num;
	char	        *str;
    int             len;

	num = va_arg(ap, unsigned int);
	str = print_hex(num, ch);
    len = ft_strlen(str);
	write(1, str, len);
	free(str);
    return (len);
}