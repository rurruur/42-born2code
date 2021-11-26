/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:46:14 by nakkim            #+#    #+#             */
/*   Updated: 2021/11/26 15:14:08 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	div;
	long long	tmp_n;
	char		c;

	if (fd < 0)
		return ;
	div = 1;
	tmp_n = (long long)n;
	if (tmp_n < 0)
	{
		write(fd, "-", 1);
		tmp_n = -tmp_n;
	}
	while (tmp_n / div > 9)
		div *= 10;
	while (div > 0)
	{
		c = tmp_n / div % 10 + 48;
		write(fd, &c, 1);
		div /= 10;
	}
}
