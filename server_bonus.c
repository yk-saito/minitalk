/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:10:47 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/12 20:20:02 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk_utils_bonus.h"

static void	server_handler(int signo, siginfo_t *info, void *context)
{
	static char		received_str[BUF_SIZE];
	static int		bit_counter;
	static size_t	index;
	ucontext_t		*ucontext;

	ucontext = (ucontext_t *)context;
	received_str[index] <<= 1;
	if (signo == SIGUSR2)
		received_str[index] |= 0x01;
	if (bit_counter++ != CHAR_BIT_INDEX)
		return ;
	if (received_str[index] == '\0')
	{
		ft_putendl_fd(received_str, STDOUT_FILENO);
		kill(info->si_pid, SIGUSR1);
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
	init_sigaction(&act, (SA_RESTART | SA_SIGINFO), &server_handler);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		put_error_and_exit("Error sigaction function(SIGUSR1).");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		put_error_and_exit("Error sigaction function(SIGUSR2).");
	while (1)
	{}
	return (EXIT_SUCCESS);
}
