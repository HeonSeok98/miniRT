/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:20:42 by klha              #+#    #+#             */
/*   Updated: 2023/10/11 14:21:03 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*send_fail_strtrim(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (0);
	str[0] = '\0';
	return (str);
}

int	determinant(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		first;
	int		last;
	int		i;

	if (!s1 || !set)
		return (0);
	first = 0;
	i = -1;
	last = ft_strlen(s1) - 1;
	while (determinant(s1[first], set) && s1[first])
		first++;
	if (first > last)
		return (send_fail_strtrim());
	while (determinant(s1[last], set))
		last--;
	str = (char *)malloc(sizeof(char) * (last - first + 2));
	if (!str)
		return (0);
	while (++i < last - first + 1)
		str[i] = s1[first + i];
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char *str;

		str = ft_strtrim(av[1], av[2]);
		printf("You typed \"%s\" and \"%s\".\nResult is \"%s\".\n", av[1], av[2], str);
		free(str);
		str = 0;
		str = ft_strtrim(0, 0);
		printf("Nul is %s\n", str);
		free(str);
		str =0;
	}
	return (0);
}
*/