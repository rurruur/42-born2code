/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:04:04 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/21 16:52:47 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
#include <fcntl.h>

// null or EOF -> add '\0'
// '\n' -> add '\n' and '\0'

unsigned long long   get_strlen(char *s)
{
    unsigned long long  len;

    len = 0;
    while(s[len])
        len++;
    return (len);
}

long long	find_end(char *buff)
{
	long long	index;

	index = -1;
	while (++index < BUFFER_SIZE)
		if (!buff[index]|| buff[index] == EOF || buff[index] == '\n')
			return (index + 1);
	return (-1);
}

void str_cpy(char *dest, char *str, long long index)
{
    while (index-- > 0)
        dest[index] = str[index];
}

char    *create_result(char *result, char *buff, long long index)
{
    char                  *dest;
    unsigned long long   dest_size;
    unsigned long long   len_result;

    len_result = get_strlen(result);
    if (index < 0)
        dest_size = len_result + BUFFER_SIZE;
    else
        dest_size = len_result + index;
    dest = (char *)malloc(sizeof(char) * (dest_size + 1));
    if (dest)
    {
        str_cpy(dest, result, len_result);
        if (index < 0)
            str_cpy(dest + len_result, buff, BUFFER_SIZE);
        else
            str_cpy(dest + len_result, buff, index);
        dest[dest_size] = '\0';
    }
    free(result);
    return (dest);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE];
	static char		*backup;
	static char		*result;
	long long		index_end;

	printf("backup: [%p] \"%s\"\n", backup, backup);
	//buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	result = (char *)malloc(sizeof(char));
	*result = '\0';
	//if (!buff)
	//	return (0);
	if (backup)
	{
		index_end = find_end(backup);
		result = create_result(result, backup, index_end);
	}
	if (read(fd, buff, BUFFER_SIZE) < 0)
		return (0);
	index_end = find_end(buff);
	result = create_result(result, buff, index_end);
	if (!result)
		return (0);
	while (index_end < 0)
	{
		if (read(fd, buff, BUFFER_SIZE) < 0)
			return (0);
		index_end = find_end(buff);
		result = create_result(result, buff, index_end);
		if (!result)
			return (0);
	}
	// 백업을 해당 위치로 옮김
	backup = buff + index_end;
	printf("backup: [%p] \"%s\"\n", backup, backup);
	//free(buff);
	return (result);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*result;

	if (argc == 1)
	{
		result = get_next_line(0);
		printf("result: %s", result);
		result = get_next_line(0);
		printf("result: %s", result);
		result = get_next_line(0);
		printf("result: %s", result);
		result = get_next_line(0);
		printf("result: %s", result);
	}
	if (argc == 2)
	{
		printf("file: %s\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			result = get_next_line(fd);
			printf("result: %s---size: %llu\n", result, get_strlen(result));
			result = get_next_line(fd);
			printf("result: %s---size: %llu\n", result, get_strlen(result));
			result = get_next_line(fd);
			printf("result: %s---size: %llu\n", result, get_strlen(result));
		}
		close(fd);
	}
	return (0);
}