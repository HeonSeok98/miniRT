/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:17:46 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 20:47:01 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;

	if (!*sub)
		return ((char *)str);
	else if (!len)
		return (0);
	while (*str && len > 0)
	{
		i = 0;
		while (*(str + i) == *(sub + i) && i < len)
		{
			i++;
			if (!*(sub + i))
				return ((char *)str);
		}
		str++;
		len--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		char	*origin;
		char	*mine;
		int		n;

		n = atoi(av[3]);
		mine = ft_strnstr(av[1], av[2], n);
		origin = strnstr(av[1], av[2], n);
		printf("You typed \"%s\", \"%s\", \"%d\".\n", av[1], av[2], n);
		if (origin)
			printf("Original result is \"Located\" and \"%s\".\n", origin);
		else
			printf("Original result is \"Not located\".\n");
		if (mine)
			printf("My result is \"Located\" and \"%s\".\n", mine);
		else
			printf("My result is \"Not located\"");
	}
	return (0);
}
*/