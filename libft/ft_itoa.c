/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:00:48 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/17 17:20:11 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*dest;
	int			len;
	long long	tmp_n;
	long long	div;

	len = 1;
	div = 10;
	tmp_n = (long long)n;
	if (tmp_n < 0)
	{
		len++;
		tmp_n = -tmp_n;
	}
	while (tmp_n / div > 0)
	{
		len++;
		div *= 10;
	}
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	*(dest + len) = '\0';
	while (div > 1)
	{
		*(dest + --len) = tmp_n % 10 + 48;
		tmp_n /= 10;
		div /= 10;
	}
	if (len)
		*(dest + --len) = '-';
	return (dest);
}
