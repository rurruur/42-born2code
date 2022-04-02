/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:58:58 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/19 11:05:32 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len_s;

	len_s = ft_strlen(s) + 1;
	dest = (char *)malloc(sizeof(char) * len_s);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s, len_s);
	return (dest);
}
