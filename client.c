/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 00:12:32 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/09 21:05:35 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk_utils.h"

void	send_char(const char send_c, const pid_t server_pid)
{
	int	bit;

	bit = CHAR_BIT_INDEX;
	while (bit >= 0)
	{
		usleep(200);
		if (send_c & (0x01 << bit))
		{
			if (kill(server_pid, SIGUSR2) == -1)
				put_error_and_exit("Error kill function.");
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
				put_error_and_exit("Error kill function.");
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
	pid_t	server_pid;
	size_t	str_len;
	size_t	index;

	if (argc != 3)
		put_error_and_exit("Error Arguments.");
	server_pid = str_to_pid(argv[1]);
	if (server_pid <= 1)
		put_error_and_exit("Error server PID.");
	str_len = ft_strlen(argv[2]);
	index = 0;
	while (index <= str_len)
	{
		send_char(argv[2][index], server_pid);
		++index;
	}
	return (EXIT_SUCCESS);
}
