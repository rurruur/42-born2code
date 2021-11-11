/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:28:24 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/10 22:21:02 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	char	*tmp_s1;
	char	*tmp_s2;
	size_t	index;

	tmp_s1 = (char *)s1;
	tmp_s2 = (char *)s2;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*tmp_s1 && tmp_s1 - size < s1)
	{
		index = 0;
		while (tmp_s1 - index - size < s1 && tmp_s1[index] && tmp_s2[index])
		{
			if (tmp_s1[index] != tmp_s2[index])
				break ;
			index++;
		}
		if (!tmp_s2[index])
			return (tmp_s1);
		tmp_s1++;
	}
	return (0);
}
