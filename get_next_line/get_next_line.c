/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:04:04 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/23 13:59:29 by nakkim           ###   ########.fr       */
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
	if (*backup)
		free(*backup);
	if (index_nl < 0)
	{
		*backup = 0;
		return (str);
	}
	result = my_strndup(str, index_nl + 1);
	*backup = my_strndup(str + index_nl + 1, my_strlen(str + index_nl + 1));
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*backup;
	char			*result;
	int				read_size;

	if (fd < 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	result = my_strndup(backup, my_strlen(backup));
	if (!result || !buff)
		return (0);
	read_size = 1;
	while (read_size > 0 && find_new_line(result) < 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		result = my_strjoin(result, buff, read_size);
		if (!result)
			return (0);
	}
	free(buff);
	if (!read_size && !(*result))
		return (0);
	return (get_result_and_backup(result, &backup));
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*result;

	if (argc == 1)
	{
		result = get_next_line(0);
		while (result)
		{
			printf("====================result: %s---size: %d\n\n", result, my_strlen(result));
			free(result);
			result = get_next_line(0);
		}
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			result = get_next_line(fd);
			while (result)
			{
				printf("=================result: %s---size: %d\n\n", result, my_strlen(result));
				free(result);
				result = get_next_line(fd);
			}
		}
		close(fd);
	}
	return (0);
}
