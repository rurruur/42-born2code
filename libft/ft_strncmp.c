/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:18:51 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/17 19:56:23 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			index;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	index = 0;
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (tmp_s1[index] && tmp_s2[index] && index < size)
	{
		if (tmp_s1[index] != tmp_s2[index])
			return (tmp_s1[index] - tmp_s2[index]);
		index++;
	}
	if (index == size)
		return (0);
	return (tmp_s1[index] - tmp_s2[index]);
}
