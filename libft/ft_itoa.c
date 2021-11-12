/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 13:05:39 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:41:59 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		num_len;

	num = n;
	num_len = get_num_len(num);
	str = malloc(sizeof(char) * (num_len + 1));
	if (str == NULL)
		return (NULL);
	str[num_len--] = '\0';
	if (n == -2147483648)
		ft_memcpy(str, "-2147483648", 11);
	else if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	else if (n == 0)
		ft_memcpy(str, "0", 1);
	while (n > 0)
	{
		str[num_len--] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}
