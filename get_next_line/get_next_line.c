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
	{
		if ( !buff[index] || buff[index] == '\n' || buff[index] == EOF)
			return (index + 1);
	}
	return (-1);
}

void str_cpy(char *dest, char *str, long long index)
{
    while (index-- > 0)
        dest[index] = str[index];
}

char	*create_new_str(char *result, char *buff, long long index)
{
	char				*dest;
    unsigned long long  dest_size;
	unsigned long long	len_result;

	len_result = get_strlen(result);
	if (index < 0)
        dest_size = len_result + BUFFER_SIZE + 1;
	else
        dest_size = len_result + index + 1;
    dest = (char *)malloc(sizeof(char) * dest_size);
    if (dest)
    {
        str_cpy(dest, result, len_result);
        if (index < 0)
            str_cpy(dest + len_result, buff, BUFFER_SIZE);
        else
            str_cpy(dest + len_result, buff, index);
    }
    free(result);
    return (dest);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*result;
	long long	index_end;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	result = (char *)malloc(sizeof(char));
	if (!buff || !result)
		return (0);
	if (read(fd, buff, BUFFER_SIZE) < 0)
		return (0);
	*result = '\0';
	index_end = find_end(buff);
	result = create_new_str(result, buff, index_end);
	while (index_end < 0)
	{
		if (read(fd, buff, BUFFER_SIZE) < 0)
			return (0);
		index_end = find_end(buff);
		result = create_new_str(result, buff, index_end);
	}
	free(buff);
	return (result);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*result;

	if (argc == 1)
	{
		result = get_next_line(0);
		printf("%s\n", result);
		free(result);
		result = get_next_line(0);
		printf("%s\n", result);
		free(result);
		result = get_next_line(0);
		printf("%s\n", result);
		free(result);
		result = get_next_line(0);
		printf("%s\n", result);
		free(result);
	}
	if (argc == 2)
	{
		printf("file: %s\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			result = get_next_line(fd);
			printf("%s\n", result);
			free(result);
			result = get_next_line(fd);
			printf("%s\n", result);
			free(result);
			result = get_next_line(fd);
			printf("%s\n", result);
			free(result);
			result = get_next_line(fd);
			printf("%s\n", result);
			free(result);
		}
		close(fd);
	}
	return (0);
}