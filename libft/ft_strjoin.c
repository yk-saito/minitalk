/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 23:07:49 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:50:19 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;

	if (!(s1) || !(s2))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(s1_len + s2_len + 1);
	if (!(newstr))
		return (NULL);
	ft_memmove(newstr, s1, s1_len);
	ft_memmove(newstr + s1_len, s2, s2_len);
	newstr[s1_len + s2_len] = '\0';
	return (newstr);
}
