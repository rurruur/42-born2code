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

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <fcntl.h>

int   my_strlen(char *s)
{
    int  len;

    len = 0;
	if (!s)
		return (0);
    while(s[len])
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

char	*my_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		len_s1;
	int		len_s2;

	len_s1 = my_strlen(s1);
	len_s2 = my_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!dest)
		return (0);
	dest[len_s1 + len_s2] = '\0';
	while (len_s2-- > 0)
		dest[len_s1 + len_s2] = s2[len_s2];
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

char	*get_result_and_backup(char *str, char **backup)
{
	char	*result;
	int		index_nl;

	if (*backup)
		free(*backup);
	if (find_new_line(str) < 0)
		return (str);
	index_nl = find_new_line(str);
	result = my_strndup(str, index_nl + 1);
	*backup = my_strndup(str + index_nl + 1, my_strlen(str + index_nl + 1));
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE];
	static char		*backup;
	char			*result;

	result = my_strndup(backup, my_strlen(backup));
	if (!result)
		return (0);
	while (find_new_line(result) < 0 && read(fd, buff, BUFFER_SIZE) > 0)
	{
		result = my_strjoin(result, buff);
		if (!result)
			return (0);
	}
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
			printf("result: %s---size: %d\n", result, my_strlen(result));
			free(result);
			puts("free result -- main");
			result = get_next_line(0);
		}
	}
	if (argc == 2)
	{
		printf("file: %s\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			result = get_next_line(fd);
			while (result)
			{
				printf("result: [%p] %s---size: %d\n", result, result, my_strlen(result));
				free(result);
				puts("free result -- main");
				result = get_next_line(fd);
			}
		}
		close(fd);
	}
	return (0);
}
