/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:41:14 by ysaito            #+#    #+#             */
/*   Updated: 2021/11/01 20:56:14 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_word_memory(char **words, int j)
{
	while (j > 0)
	{
		j--;
		free(words[j]);
	}
	free(words);
	return (NULL);
}

static int	get_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**split_words(char const *s, char **words, char c, int words_num)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words_num)
	{
		k = 0;
		while (s[i] == c)
			i++;
		words[j] = malloc(sizeof(char) * get_len(s, c, i) + 1);
		if (words[j] == NULL)
			return (free_word_memory(words, j));
		while (s[i] != '\0' && s[i] != c)
			words[j][k++] = s[i++];
		words[j][k] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}

static int	get_num_of_words(char const *s, char c)
{
	int		i;
	int		count;
	int		flag;

	if (s[0] == '\0')
		return (0);
	i = 0;
	count = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		words_num;

	if (s == NULL)
		return (NULL);
	words_num = get_num_of_words(s, c);
	words = malloc(sizeof(char *) * (words_num + 1));
	if (words == NULL)
		return (NULL);
	return (split_words(s, words, c, words_num));
}
