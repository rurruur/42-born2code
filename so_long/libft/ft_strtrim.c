/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:29:10 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/19 11:43:50 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
		if (c == set[index++])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set) && s1[start])
		start++;
	if (!s1[start])
		return ((char *)ft_calloc(1, sizeof(char)));
	while (is_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
