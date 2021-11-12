/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:24:01 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/12 20:19:42 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk_utils.h"

void	server_handler(int signo)
{
	static char		received_str[BUF_SIZE];
	static int		bit_counter;
	static size_t	index;

	received_str[index] <<= 1;
	if (signo == SIGUSR2)
		received_str[index] |= 0x01;
	if (bit_counter++ != CHAR_BIT_INDEX)
		return ;
	if (received_str[index] == '\0')
	{
		ft_putendl_fd(received_str, STDOUT_FILENO);
		index = -1;
	}
	else if (index == (BUF_SIZE - 2))
	{
		received_str[++index] = '\0';
		ft_putstr_fd(received_str, STDOUT_FILENO);
		index = -1;
	}
	bit_counter = 0;
	++index;
}

static void	put_ownpid(void)
{
	ft_putstr_fd("server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

int	main(void)
{
	struct sigaction	act;

	put_ownpid();
	sigemptyset(&act.sa_mask);
	act.sa_handler = server_handler;
	act.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		put_error_and_exit("Error sigaction function(SIGUSR1).");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		put_error_and_exit("Error sigaction function(SIGUSR2).");
	while (1)
	{}
	return (EXIT_SUCCESS);
}
