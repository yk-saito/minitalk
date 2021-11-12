/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:10:25 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/06 21:45:49 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_BONUS_H
# define MINITALK_UTILS_BONUS_H
# define BUF_SIZE 1024
# define CHAR_BIT_INDEX 7

# include <signal.h>

void	init_sigaction(
			struct sigaction *act,
			const int flags,
			void (*handler)(int, siginfo_t *, void *));
void	put_error_and_exit(char *putstr);

#endif
