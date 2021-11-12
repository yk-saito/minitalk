/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:56:59 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:50:31 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;

	if (dst == NULL || src == NULL)
		return (0);
	slen = ft_strlen(src);
	if (slen + 1 < dstsize)
	{
		ft_memcpy(dst, src, slen + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, (dstsize - 1));
		dst[dstsize - 1] = '\0';
	}
	return (slen);
}
