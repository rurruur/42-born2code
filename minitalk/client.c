/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:34 by nakkim            #+#    #+#             */
/*   Updated: 2022/03/30 13:31:47 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

void	send_char(int pid, char ch)
{
	int	count;
	int	result;

	count = 7;
	while (count-- > 0)
	{
		if (ch % 2 == 0)
			result = kill(pid, SIGUSR1); // 30
		else
			result = kill(pid, SIGUSR2); // 31
		if (result == -1)
			exit(1);
		ch /= 2;
		usleep(50);
	}
}

void	deliver(char *pid, char *str)
{
	int	index;

	index = -1;
	while (str[++index])
		send_char(ft_atoi(pid), str[index]);
	send_char(ft_atoi(pid), 127);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);
	deliver(argv[1], argv[2]);

	return (0);
}