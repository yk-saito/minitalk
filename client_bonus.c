/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:08:24 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/11 14:23:55 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk_utils_bonus.h"

int	g_exit_flag;

static void	client_handler(int signo, siginfo_t *info, void *context)
{
	ucontext_t	*ucontext;

	ucontext = (ucontext_t *)context;
	if (signo == SIGUSR1)
	{
		ft_putstr_fd("Received SIGNAL from PID: ", STDOUT_FILENO);
		ft_putnbr_fd(info->si_pid, STDOUT_FILENO);
		g_exit_flag = 1;
	}
}

static void	send_char(const char send_c, const pid_t server_pid)
{
	int	bit;

	bit = CHAR_BIT_INDEX;
	while (bit >= 0)
	{
		usleep(200);
		if (send_c & (0x01 << bit))
		{
			if (kill(server_pid, SIGUSR2) == -1)
				put_error_and_exit("Error kill(SIGUSR2) function.");
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
				put_error_and_exit("Error kill(SIGUSR1) function.");
		}
		--bit;
	}
}

pid_t	str_to_pid(const char *str)
{
	int		minus;
	int		ov_div;
	pid_t	pid;
	size_t	str_len;

	minus = 1;
	pid = 0;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	str_len = ft_strlen(str);
	if (str_len > 10)
		return (0);
	ov_div = INT_MAX / 10;
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((pid > ov_div) || (minus == -1 && ((pid == ov_div) && (*str > '8')))
			|| (minus == 1 && ((pid == ov_div) && (*str > '7'))))
			return (0);
		pid = pid * 10 + (*str - '0');
		str++;
	}
	return (pid * minus);
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	pid_t				server_pid;
	size_t				str_len;
	size_t				index;

	if (argc != 3)
		put_error_and_exit("Error Arguments.");
	server_pid = str_to_pid(argv[1]);
	if (server_pid <= 1)
		put_error_and_exit("Error server PID.");
	init_sigaction(&act, (SA_RESTART | SA_SIGINFO), &client_handler);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		put_error_and_exit("Error sigaction function.");
	str_len = ft_strlen(argv[2]);
	index = 0;
	while (index <= str_len)
		send_char(argv[2][index++], server_pid);
	while (1)
	{
		if (g_exit_flag == 1)
			break ;
		pause();
	}
	return (EXIT_SUCCESS);
}
