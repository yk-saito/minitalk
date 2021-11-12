/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:24:03 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:46:43 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;
	unsigned char		uc;
	size_t				i;

	dp = (unsigned char *)dst;
	sp = (const unsigned char *)src;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dp[i] = sp[i];
		if (dp[i] == uc)
		{
			i++;
			return ((void *)dp + i);
		}
		i++;
	}
	return (NULL);
}
