/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:55:46 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:48:24 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_output_num(long ln, int fd)
{
	if (ln == -2147483648)
		write(fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c[10];
	long	ln;
	int		i;

	ln = n;
	i = 0;
	if ((ln < -2147483648 || ln > 2147483647) || ln == -2147483648)
	{
		ft_output_num(ln, fd);
		return ;
	}
	else if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	else if (ln == 0)
		write(fd, "0", 1);
	while (ln)
	{
		c[i++] = '0' + (ln % 10);
		ln = ln / 10;
	}
	while (i)
		write(fd, &c[--i], 1);
}
