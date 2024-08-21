/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:19:49 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 20:19:50 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) ptr1;
	str2 = (unsigned char *) ptr2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/*
What if str1 and str2 is very short and n is too large? 
Such as lenths of str1 and str2 are 2 of them, but n is 1 mil.

man memcmp says 
"The memcmp() function compares byte string s1 against byte string s2.  
Both strings are assumed to be n bytes long.".
So they have a same lenth of them and also the lenth same as n?

#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		char	*first;
		char	*second;
		int		diff;
		int		result;
		int		origin;

		first = av[1];
		second = av[2];
		diff = atoi(av[3]);
		result = ft_memcmp(first, second, diff);
		origin = memcmp(first, second, diff);
		printf("Original result is ");
		if (origin)
			printf("Two blocks are diffent. difference is %d\n", origin);
		else
			printf("They are same\n");
		printf("My result is ");
		if (result)
			printf("Two blocks are diffent. difference is %d\n", result);
		else
			printf("They are same\n");
	}
	return (0);
}
*/