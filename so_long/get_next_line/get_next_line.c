/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:04:04 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 15:39:33 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_result_and_backup(char *str, char **backup)
{
	char	*result;
	int		index_nl;

	index_nl = find_new_line(str);
	if (index_nl < 0)
		return (str);
	result = my_strndup(str, index_nl + 1);
	*backup = my_strndup(str + index_nl + 1, my_strlen(str + index_nl + 1));
	free(str);
	return (result);
}

int	get_result(char **result, int *read_size, int fd)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (0);
	while (*read_size > 0 && find_new_line(*result) < 0)
	{
		*read_size = read(fd, buff, BUFFER_SIZE);
		if (*read_size < 0)
		{
			free(buff);
			free(*result);
			return (0);
		}
		*result = my_strjoin(*result, buff, *read_size);
		if (!(*result))
			return (0);
	}
	free(buff);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*result;
	int				read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	result = my_strndup(backup, my_strlen(backup));
	read_size = 1;
	if (backup)
	{
		free(backup);
		backup = 0;
	}
	if (!result)
		return (0);
	if (find_new_line(result) < 0 && !get_result(&result, &read_size, fd))
		return (0);
	if (!read_size && !(*result))
	{
		free(result);
		return (0);
	}
	return (get_result_and_backup(result, &backup));
}
