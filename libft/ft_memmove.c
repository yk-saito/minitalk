/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 14:19:37 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:47:48 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dp;
	char	*sp;

	dp = (char *)dst;
	sp = (char *)src;
	if (len == 0 || dp == sp)
		return (dst);
	else if (dp < sp)
		return (ft_memcpy(dst, src, len));
	else
	{
		dp += len - 1;
		sp += len - 1;
		while (len--)
		{
			*dp-- = *sp--;
		}
	}
	return (dst);
}
