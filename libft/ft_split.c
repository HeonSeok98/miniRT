/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:12:55 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 21:12:56 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	**free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = 0;
		i++;
	}
	free(split);
	split = 0;
	return (0);
}

int	word_len(char const *s, char c)
{
	int	n;

	n = 0;
	while (s[n] && s[n] != c)
		n++;
	return (n);
}

char	*set_word(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	len = 1 + word_len(s, c);
	word = (char *)malloc(sizeof(char) * len);
	if (!word)
		return (0);
	i = ft_strlcpy(word, s, len);
	return (word);
}

int	count_word(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	i = 0;
	if (!s)
		return (0);
	split = (char **)malloc(sizeof(char *) * (1 + count_word(s, c)));
	if (!split)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split[i] = set_word(s, c);
			if (!split[i++])
				return (free_split(split));
		}
		while (*s && *s != c)
			s++;
	}
	split[i] = 0;
	return (split);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	delimiter;
		char	*origin;
		char	**result;

		origin = av[1];
		delimiter = av[2][0];
		result = ft_split(origin, delimiter);
		printf("You typed \"%s\" and \"%c\".\n", origin, delimiter);
		printf("Result is down below.\n");
		printf("====================================\n");
		for (int i = 0; result[i]; i++)
			printf("\"%s\"\n", result[i]);
		printf("====================================\n");
	}
	return (0);
}
*/