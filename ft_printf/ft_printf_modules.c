#include "ft_printf.h"

static int	get_len(unsigned int n)
{
    int len;

	len = 1;
	while (n / 10 > 0)
	{
		len++;
        n /= 10;
	}
    return (len);
}

char    *ft_ltoa(unsigned int n)
{
    char		    *dest;
	int			    len;

    len = get_len(n);
    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (0);
    dest[len] = '\0';
    while (--len >= 0)
    {
        dest[len] = n % 10 + 48;
        n /= 10;
    }
	return (dest);
}

static int  get_hex_len(unsigned int n)
{
    int len;

    len = 1;
    while (n / 16 > 0)
    {
        len++;
        n /= 16;
    }
    return (len);
}

char    *print_hex(unsigned int n, char c)
{
    char            asdf;
    char		    *dest;
	int			    len;

    len = get_hex_len(n);
    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (0);
    dest[len] = '\0';
    while (--len >= 0)
    {
        asdf = n % 16;
        dest[len] = asdf + 48;
        if (asdf > 9)
        {
            dest[len] = asdf + 'a' - 10;
            if (c == 'X')
               dest[len] = asdf + 'A' - 10;
        }
        n /= 16;
    }
	return (dest);
}

int handle_seosick(va_list ap, char current_c)
{
	if (current_c == 'c')
		return (handle_c(ap));
	if (current_c == 's')
		return (handle_s(ap));
	if (current_c == 'd' || current_c == 'i')
		return (handle_d_i(ap));
	if (current_c == 'u')
		return (handle_u(ap));
	if (current_c == 'x' || current_c == 'X')
		return (handle_x_X(ap, current_c));
	if (current_c == '%')
    {
		write(1, "%", 1);
        return (1);
    }
    return (0);
}