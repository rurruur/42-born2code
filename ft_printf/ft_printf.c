/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:36:04 by nakkim            #+#    #+#             */
/*   Updated: 2021/12/01 18:36:05 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_seosick(unsigned char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	print_address(unsigned long long address, int ptr_size, int size)
{
	int	num;

	while (ptr_size-- > 0)
	{
		num = (address >> (ptr_size * 4)) & 15;
		if (num > 9)
			num += 'a' - 10;
		else
			num += '0';
		write(1, &num, 1);
		size++;
	}
	return (size);
}

int	handle_p(va_list ap)
{
	unsigned long long	address;
	int					ptr_size;
	int					size;

	size = 2;
	ptr_size = sizeof(void *) * 2;
	address = va_arg(ap, unsigned long long);
	write(1, "0x", 2);
	while (ptr_size-- > 0)
	{
		if ((address >> (ptr_size * 4) & 15) != 0)
		{
			ptr_size++;
			break ;
		}
	}
	if (ptr_size == -1)
	{
		write(1, "0", 1);
		size++;
	}
	else
		size = print_address(address, ptr_size, size);
	return (size);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		index;
	int		len;

	len = 0;
	index = -1;
	va_start(ap, s);
	while (s[++index])
	{
		if (s[index] != '%')
		{
			write(1, &(s[index]), 1);
			len++;
			continue ;
		}
		//if (!s[index + 1] || !is_seosick(s[index + 1]))
			// Err!
		index++;
		len += handle_seosick(ap, s[index]);
	}
	va_end(ap);
	return (len);
}
