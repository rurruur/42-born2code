/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:30:33 by nakkim            #+#    #+#             */
/*   Updated: 2022/06/14 14:35:20 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*my_strndup(char *src, int size)
{
	char	*dest;
	int		index;

	index = -1;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	while (++index < size && src[index])
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}

char	*my_strjoin(char *s1, char *s2, int read_size)
{
	char	*dest;
	int		len_s1;

	len_s1 = my_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len_s1 + read_size + 1));
	if (!dest)
		return (0);
	dest[len_s1 + read_size] = '\0';
	while (read_size-- > 0)
		dest[len_s1 + read_size] = s2[read_size];
	while (len_s1-- > 0)
		dest[len_s1] = s1[len_s1];
	free(s1);
	return (dest);
}

int	find_new_line(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
		if (str[index] == '\n')
			return (index);
	return (-1);
}
