/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:22 by nakkim            #+#    #+#             */
/*   Updated: 2022/03/29 17:30:34 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

void printPID(int pid) {
	char *str;

	str = ft_itoa(pid);
	if (!str)
		exit(1);
	write(1, "process id: ", 12);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

void signal_handler(int sig) {
	static int	count;
	static char	ch;

	if (--count < 1)
	{
		count = 7;
		ch = 0;
	}
	ch |= ((sig % 2)<<(7-count));
	if (count == 1)
	{
		if (ch == 127)
			write(1, "\n", 1);
		else
			write(1, &ch, 1);
	}
}

int main(void)
{
	struct sigaction act;
	int		result;

	act.sa_handler = signal_handler;
	// sa_mask: 시그널 처리하는 동안 블록시킬 시그널 집합인데 비워뒀으므로 모든 시그널 블록되지 않음
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0; // sa_flag?
	result = sigaction(SIGUSR1, &act, NULL);
	result += sigaction(SIGUSR2, &act, NULL);
	if (result != 0)
		exit(1);
	printPID(getpid());

	while (1) {
		pause();
	}

	return (0);
}