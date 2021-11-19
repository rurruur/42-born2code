/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:44:38 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/19 13:01:43 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_arr_size(char *s, char c)
{
	int	arr_size;
	int	flag;

	flag = 1;
	arr_size = 1;
	while (*s)
	{
		if (!flag && *s == c)
			flag = 1;
		if (flag && *s != c)
		{
			arr_size++;
			flag = 0;
		}
		s++;
	}
	return (arr_size);
}

static void	free_all(char **dest, int dest_index)
{
	while (dest_index-- > 0)
		free(dest[dest_index]);
}

static int	alloc_and_copy(char **dest, char *s, int size, int dest_index)
{
	dest[dest_index] = (char *)malloc(sizeof(char) * (size + 1));
	if (!(dest[dest_index]))
	{
		free_all(dest, dest_index);
		return (0);
	}
	ft_strlcpy(dest[dest_index], s - size, size + 1);
	return (1);
}

static int	alloc_each(char **dest, char *s, char c, int dest_index)
{
	int	size;

	size = 0;
	while (*s)
	{
		if (*s == c && size)
		{
			dest[dest_index] = (char *)malloc(sizeof(char) * (size + 1));
			if (!alloc_and_copy(dest, s, size, dest_index))
				return (0);
			dest_index++;
			size = 0;
		}
		if (*s != c)
			size++;
		s++;
	}
	if (size && !alloc_and_copy(dest, s, size, dest_index))
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	char	*tmp_s;
	int		arr_size;

	tmp_s = (char *)s;
	while (*tmp_s == c && *tmp_s)
		tmp_s++;
	arr_size = get_arr_size(tmp_s, c);
	dest = (char **)malloc(sizeof(char *) * arr_size);
	if (!dest)
		return (0);
	dest[--arr_size] = 0;
	if (!alloc_each(dest, tmp_s, c, 0))
		free(dest);
	return (dest);
}
