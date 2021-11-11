/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:10:03 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/10 23:08:54 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (const unsigned char *)src;
	if (dest > src)
	{
		while (n-- > 0)
			dest2[n] = src2[n];
	}
	else
	{
		while (n-- > 0)
			*dest2++ = *src2++;
	}
	return (dest);
}
