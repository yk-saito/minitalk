/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 11:11:37 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:50:27 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= dstsize)
		return (dstsize + slen);
	else if (slen <= (dstsize - dlen - 1))
		ft_memcpy((dst + dlen), src, (slen + 1));
	else if (dstsize != 0)
	{
		ft_memcpy((dst + dlen), src, (dstsize - dlen - 1));
		dst[dstsize - 1] = '\0';
	}
	return ((dlen + slen));
}
