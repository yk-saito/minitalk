/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:53:03 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/04 16:51:08 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bp;
	unsigned char	uc;
	size_t			index;

	bp = (unsigned char *)b;
	uc = (unsigned char)c;
	index = 0;
	while (index < len)
	{
		bp[index] = c;
		index++;
	}
	return (b);
}
