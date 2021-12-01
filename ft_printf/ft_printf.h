/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:36:18 by nakkim            #+#    #+#             */
/*   Updated: 2021/12/01 18:36:19 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINTF_H
#define F_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

int     ft_printf(const char *s, ...);
char    *ft_ltoa(unsigned int n);
char    *print_hex(unsigned int n, char c);
int     handle_seosick(va_list ap, char current_c);
int     handle_c(va_list ap);
int     handle_d_i(va_list ap);
int     handle_s(va_list ap);
int     handle_u(va_list ap);
int     handle_x_X(va_list ap, char ch);

#endif