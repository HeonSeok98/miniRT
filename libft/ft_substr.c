/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:12:14 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 21:12:15 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*send_fail(void)
{
	char	*substr;

	substr = (char *)malloc(sizeof(char));
	if (!substr)
		return (0);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	n;

	if (!s)
		return (send_fail());
	n = ft_strlen(s);
	i = 0;
	if (start >= n)
		return (send_fail());
	if (n - start < len)
		len = n - start;
	substr = (char *)malloc(len * sizeof(char) + 1);
	if (!substr)
		return (0);
	while (s[i + start] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		char *str;
		size_t start = atoi(av[2]);
		size_t len = atoi(av[3]);

		str = ft_substr(av[1], start, len);
		printf("You typed \"%s\",\"%s\",\"%s\".\n", av[1], av[2], av[3]);
		printf("Result is \"%s\".", str);
		free(str);
	}
	return (0);
}
*/