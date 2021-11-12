/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:39:50 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/12 20:41:08 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error arguments\n");
		return (EXIT_FAILURE);
	}
	for (int i = 0; i < 3; ++i)
	{
		sleep(3);
		if (i == 0)
		{
			printf("\nSend SIGUSR1\n");
			kill((pid_t)atoi(argv[1]), SIGUSR1);
		}
		else if (i == 1)
		{
			printf("\nSend SIGUSR2\n");
			kill((pid_t)atoi(argv[1]), SIGUSR2);
		}
		else
		{
			printf("\nSend SIGINT\n");
			kill((pid_t)atoi(argv[1]), SIGINT);
		}
	}
	return (EXIT_SUCCESS);
}
