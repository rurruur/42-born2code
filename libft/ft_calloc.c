/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:39:04 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/11 21:44:10 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t arr_size, size_t size)
{
	void	*ptr;

	ptr = malloc(arr_size * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
}
