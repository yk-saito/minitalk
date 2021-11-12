/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:31:01 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 21:03:56 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	newlen;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen || len == 0)
		return (ft_strdup(""));
	newlen = slen - start;
	if (newlen > len)
		newlen = len;
	new = malloc(sizeof(char *) * (newlen + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && newlen-- > 0)
	{
		new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}
