/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:49:45 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/05 21:21:50 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk_utils_bonus.h"

void	init_sigaction(struct sigaction *act,
					   const int flags,
					   void (*handler)(int, siginfo_t *, void *))
{
	sigemptyset(&act->sa_mask);
	act->sa_flags = flags;
	act->sa_sigaction = handler;
}

void	put_error_and_exit(char *putstr)
{
	ft_putendl_fd(putstr, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
