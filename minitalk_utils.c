/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:35:59 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/05 21:21:41 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk_utils.h"

void	put_error_and_exit(char *putstr)
{
	ft_putendl_fd(putstr, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
