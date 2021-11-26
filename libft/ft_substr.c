/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:07:31 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/26 15:10:33 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;
	size_t	index;

	index = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len_s - start >= len)
		substr = (char *)malloc(sizeof(char) * (len + 1));
	else
		substr = (char *)malloc(sizeof(char) * (len_s - start + 1));
	if (!substr)
		return (0);
	while (s[start + index] && index < len)
	{
		substr[index] = s[start + index];
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
