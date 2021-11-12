/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:39:34 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/12 20:44:27 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void signal_handler(int signo)
{
	if (signo == SIGUSR1)
		write(STDOUT_FILENO, "\ncought SIGUSR1 !\n", 19);
	else if (signo == SIGUSR2)
		write(STDOUT_FILENO, "\ncought SIGUSR2 !\n", 19);
	else if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\ncought SIGINT !!!\n", 20);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		write(STDOUT_FILENO, "\nError cought signo: %d\n", 25);
		_exit(EXIT_FAILURE);
	}
}

int main(void)
{
	pid_t				pid;
	struct sigaction	sa_sigint;

	pid = getpid();
	printf("%d\n", (int)pid);

	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	sa_sigint.sa_handler = signal_handler;

	if (sigaction(SIGUSR1, &sa_sigint, NULL) < 0)
	{
		perror("sigaction SIGUSR1");
		return (EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa_sigint, NULL) < 0)
	{
		perror("sigaction SIGUSR2");
		return (EXIT_FAILURE);
	}
	if (sigaction(SIGINT, &sa_sigint, NULL) < 0)
	{
		perror("sigaction SIGINT");
		return (EXIT_FAILURE);
	}

	while (1)
	{
		printf("\npause()...\n");
		pause();
		printf("return from pause()\n");
	}
	return (EXIT_SUCCESS);
}
