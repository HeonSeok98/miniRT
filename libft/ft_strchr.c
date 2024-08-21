/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:19:04 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 15:23:50 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	n;

	n = (char)c;
	while (*str)
	{
		if (*str == n)
			return ((char *)str);
		str++;
	}
	if (n == *str)
		return ((char *)str);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	*origin;
		char	*mine;

		mine = ft_strchr(av[1], av[2][0]);
		origin = strchr(av[1], av[2][0]);
		printf("You typed \"%s\" and \"%c\".\n", av[1], av[2][0]);
		if (origin)
			printf("Original result is \"Located\" and \"%s\".\n", origin);
		else
			printf("Original result is \"Not located\".\n");
		if (mine)
			printf("My result is \"Located\" and \"%s\".\n", mine);
		else
			printf("My result is \"Not located\".\n");
	}
	return (0);
}
*/