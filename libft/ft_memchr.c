/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:06:45 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 20:06:46 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	value;
	unsigned char	*str;

	value = (unsigned char) c;
	str = (unsigned char *) ptr;
	while (n > 0)
	{
		if (*str == value)
			return ((void *)str);
		str++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		char *str;
		char *test;
		char target;

		str = av[1];
		target = av[2][0];
		test = (char *)ft_memchr(str, target, atoi(av[3]));
		if (test != 0)
			printf("\'%c\' found at position %ld.\n", target, test - str + 1);
		else
			printf("Can't found \'%c\'\n", target);
	}
	return (0);
}
*/