/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:40:38 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/11 13:01:54 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		if (((char *)str)[index] == ch)
			return (&((char *)str)[index]);
		index++;
	}
	return (0);
}
