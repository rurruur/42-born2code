/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:22 by nakkim            #+#    #+#             */
/*   Updated: 2022/04/04 13:55:16 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

void	print_pid(int pid)
{
	char	*str;

	str = ft_itoa(pid);
	if (!str)
		exit(1);
	write(1, "process id: ", 12);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

void	signal_handler(int sig, siginfo_t *info, void *uap)
{
	static int				count;
	static unsigned char	ch;

	(void)uap;
	if (--count < 1)
	{
		count = 8;
		ch = 0;
	}
	ch |= ((sig % 2) << (8 - count));
	if (count == 1)
	{
		if (ch == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &ch, 1);
	}
}

int	main(void)
{
	struct sigaction	act;
	int					result;

	act.sa_sigaction = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	result = sigaction(SIGUSR1, &act, NULL);
	result += sigaction(SIGUSR2, &act, NULL);
	if (result != 0)
		exit(1);
	print_pid(getpid());
	while (1)
		pause();
	return (0);
}
