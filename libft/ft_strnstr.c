/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:28:24 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/17 19:43:50 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	index_s1;
	size_t	index;

	index_s1 = 0;
	while (s1[index_s1] && index_s1 < size)
	{
		index = 0;
		while (s1[index_s1 + index] && s2[index] && index + index_s1 < size)
		{
			if (s1[index_s1 + index] != s2[index])
				break ;
			index++;
		}
		if (!s2[index])
			return ((char *)(s1 + index_s1));
		index_s1++;
	}
	return (0);
}
