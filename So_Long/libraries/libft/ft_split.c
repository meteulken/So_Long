/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:54:33 by mulken            #+#    #+#             */
/*   Updated: 2022/10/13 22:11:53 by mulken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(const char *str, char c)
{
	int	index;
	int	dot;
	int	trigger;

	index = 0;
	dot = 0;
	trigger = 0;
	while (str[index] != '\0')
	{
		if (str[index] != c && trigger == 0)
		{
				trigger = 1;
				dot++;
		}
		else if (str[index] == c)
				trigger = 0;
		index++;
	}
	return (dot);
}

static char	*ft_word_dup(const char *str, int start, int end)
{
	int		index;
	char	*word;

	index = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
			word[index] = str[start];
			start++;
			index++;
	}
	word[index] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	index;
	int		spindex;
	int		start;

	if (!s)
		return (0);
	index = -1;
	spindex = 0;
	start = -1;
	split = malloc(sizeof(char *) * (ft_word_counter(s, c) + 1));
	if (!split)
		return (0);
	while (++index <= ft_strlen(s))
	{
		if (s[index] != c && start < 0)
			start = index;
		else if ((s[index] == c || index == ft_strlen(s)) && start >= 0)
		{
			split[spindex++] = ft_word_dup(s, start, index);
			start = -1;
		}
	}
	split[spindex] = NULL;
	return (split);
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "mete ulken hello world";
	char set = ' ';
	char **sonuc;

	int i = -1;

	sonuc = ft_split(str,set);

	while(i++ < 3)
	{
		printf("%d. dizi: %s\n", i,sonuc[i]);
	}
	return 0;
}*/
