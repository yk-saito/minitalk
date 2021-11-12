/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:30:56 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/12 20:33:46 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void    ft_show_bits(char c)
{
    for (int i = 7; i >= 0; --i)
    {
        if (c & (0x01 << i))
            write(STDOUT_FILENO, "1", 1);
        else
            write(STDOUT_FILENO, "0", 1);
    }
    write(STDOUT_FILENO, "\n", 1);
}

void    signal_handler(int signo)
{
    static char	received_str[BUFSIZ];
    static int	index;
    static int	bit_counter;

    received_str[index] <<= 1;
    if (signo == SIGUSR2)
        received_str[index] |= 0x01;
	ft_show_bits(received_str[index]);
    if (bit_counter++ != 7)
        return ;
	if (received_str[index] == '\0')
	{
		write(STDOUT_FILENO, received_str, strlen(received_str));
		write(1, "\n", 1);
		index = -1;
	}
	else if (index == (BUFSIZ - 2))
	{
		received_str[++index] = '\0';
		write(STDOUT_FILENO, received_str, strlen(received_str));
		index = -1;
	}
	bit_counter = 0;
	++index;
	write(1, "\n", 1);
}

int main(void)
{
	pid_t               pid;
	struct sigaction    act;

	pid = getpid();
	printf("server PID: %d\n", (int)pid);

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	act.sa_handler = signal_handler;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
	{
		perror("sigaction SIGUSR1");
		return (EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &act, NULL) < 0)
	{
		perror("sigaction SIGUSR2");
		return (EXIT_FAILURE);
	}
	while (1)
	{}
	return (EXIT_SUCCESS);
}
