/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:08:01 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:46:36 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sp;
	unsigned char		uc;

	sp = (const unsigned char *)s;
	uc = c;
	while (n-- > 0)
	{
		if (*sp == uc)
		{
			return ((void *)sp);
		}
		sp++;
	}
	return (NULL);
}
