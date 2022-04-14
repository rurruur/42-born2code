/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:12:40 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/14 15:54:15 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*get_result_and_backup(char *str, char **backup);
int		find_new_line(char *str);
char	*my_strjoin(char *s1, char *s2, int read_size);
char	*my_strndup(char *src, int size);
int		my_strlen(char *s);

#endif
