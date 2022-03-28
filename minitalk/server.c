/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakkim <nakkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:20:22 by nakkim            #+#    #+#             */
/*   Updated: 2022/03/28 21:50:48 by nakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

void printPID(int pid) {
	char *str;

	str = ft_itoa(pid);
	write(1, "process id: ", 12);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

void signal_handler(int sig) {
	write(1, "signal handler\n", 15);
}

int main(void)
{
	struct sigaction act;

	act.sa_handler = signal_handler;
	sigemptyset(&act.sa_mask); // ?
	printPID(getpid());
	sigaction(SIGUSR1, &act, 0);

	// kill -SIGUSR1 [pid] -> 핸들러 실행
	while (1) {
		write(1, "--\n", 3);
		sleep(1);
	}

	return (0);
}