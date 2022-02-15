/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:16:06 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/11 18:44:20 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	index;

	index = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (n < len_dest + 1)
		return (n + len_src);
	while (index < n - len_dest - 1 && src[index])
	{
		dest[len_dest + index] = src[index];
		index++;
	}
	dest[len_dest + index] = '\0';
	return (len_dest + len_src);
}
