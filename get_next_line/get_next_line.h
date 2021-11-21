/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:12:40 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/21 16:13:35 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

unsigned long long   get_strlen(char *s);
long long            find_end(char *buff);
void                 str_cpy(char *dest, char *str, int index);
char	                *create_new_str(char *result, char *buff, int index);

#endif
