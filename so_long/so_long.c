/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:20:12 by nakkim            #+#    #+#             */
/*   Updated: 2022/05/25 15:57:40 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	index;
	size_t	len_src;

	index = 0;
	len_src = ft_strlen(src);
	if (n == 0)
		return (len_src);
	while (index < n - 1 && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (len_src);
}

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

void	set_map_info(t_solong *info, char *file)
{
	int		fd;
	char	*result;
	int		width;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	// gnl 에러 확인
	result = get_next_line(fd);
	height = 0;
	while (result)
	{
		width = 0;
		while (result[width])
			width++;
		info->width = width;
		height++;
		free(result);
		result = get_next_line(fd);
	}
	info->height = height;
	close(fd);
}

void	get_map(t_solong *info, char *file)
{
	int		fd;
	char	*result;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	height = 0;
	info->map = (char **)malloc(sizeof(char *) * info->height);
	result = get_next_line(fd);
	while (height < info->height)
	{
		// parse map
		info->map[height] = ft_strdup(result);
		printf("%s\n", info->map[height]);
		height++;
		free(result);
		result = get_next_line(fd);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_solong	info;
	
	if (argc != 2)
		return (0);
	set_map_info(&info, argv[1]);
	printf("width: %d, height: %d\n", info.width, info.height);
	get_map(&info, argv[1]);
	return (0);
}