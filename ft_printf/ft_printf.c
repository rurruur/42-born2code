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
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
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
			continue;
		}
		//if (!s[index + 1] || !is_seosick(s[index + 1]))
			// Err!
		index++;
		len += handle_seosick(ap, s[index]);
	}
	va_end(ap);
	return (len);
}