#include "ft_printf.h"

static int	get_len(unsigned int tmp_n)
{
    int len;

	len = 1;
	while (tmp_n / 10 > 0)
	{
		len++;
        tmp_n /= 10;
	}
    return (len);
}

char    *ft_ltoa(int n)
{
    char		    *dest;
	int			    len;
	unsigned int    tmp_n;

    tmp_n = (unsigned int)n;
    len = get_len(tmp_n);
    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (0);
    dest[len] = '\0';
    while (--len >= 0)
    {
        dest[len] = tmp_n % 10 + 48;
        tmp_n /= 10;
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

char    *print_hex(int n, char c)
{
    char            asdf;
    char		    *dest;
	int			    len;
	unsigned int    tmp_n;

    tmp_n = (unsigned int)n;
    len = get_hex_len(tmp_n);
    dest = (char *)malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (0);
    dest[len] = '\0';
    while (--len >= 0)
    {
        asdf = tmp_n % 16;
        dest[len] = asdf + 48;
        if (asdf > 9)
        {
            dest[len] = asdf + 'a' - 10;
            if (c == 'X')
               dest[len] = asdf + 'A' - 10;
        }
        tmp_n /= 16;
    }
	return (dest);
}