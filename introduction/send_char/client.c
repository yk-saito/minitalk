/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:30:59 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/12 20:33:33 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define CHAR_BIT_INDEX 7

void	send_char(const char send_c, const pid_t server_pid)
{
	int	bit;

	bit = CHAR_BIT_INDEX;
	while (bit >= 0)
	{
		sleep(1);
		if (send_c & (0x01 << bit))
        {
            write(STDOUT_FILENO, "1", 1);
			kill(server_pid, SIGUSR2);
        }
        else
		{
            write(STDOUT_FILENO, "0", 1);
        	kill(server_pid, SIGUSR1);
        }
        --bit;
	}
    write(STDOUT_FILENO, "\n", 1);
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	size_t	str_len;
	size_t	index;

	if (argc != 3)
    {
		perror("Error Arguments.");
        return (EXIT_FAILURE);
    }
    server_pid = (pid_t)atoi(argv[1]);
	if (server_pid <= 1)
    {
		perror("Error server PID.");
        return (EXIT_FAILURE);
    }
	str_len = strlen(argv[2]);
	index = 0;
	while (index <= str_len)
	{
		send_char(argv[2][index], server_pid);
		++index;
	}
	return (EXIT_SUCCESS);
}
