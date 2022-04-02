/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:34 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/02 16:00:17 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

void	send_char(int pid, unsigned char ch)
{
	int	count;
	int	result;

	count = 8;
	while (count-- > 0)
	{
		if (ch % 2 == 0)
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		if (result == -1)
		{
			write(1, "fail.\n", 6);
			exit(1);
		}
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
	send_char(ft_atoi(pid), 0);
}

void	print_result(int signo)
{
	(void)signo;
	write(1, "done.\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	act.sa_handler = print_result;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	if (argc != 3)
		return (1);
	deliver(argv[1], argv[2]);
	sleep(3);
	write(1, "fail.\n", 6);
	return (0);
}
