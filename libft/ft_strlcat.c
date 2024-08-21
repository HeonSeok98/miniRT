/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:35:17 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 16:35:21 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	size_t			n;

	len_src = ft_strlen(src);
	if (!size)
		return (len_src);
	len_dest = ft_strlen(dest);
	n = len_dest;
	if (size <= len_dest)
		return (len_src + size);
	while (n + 1 < size && *src != '\0')
	{
		*(dest + n) = *src;
		src++;
		n++;
	}
	if (n < size)
		dest[n] = '\0';
	else
		dest[size - 1] = '\0';
	return (len_dest + len_src);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		size_t	origin_test;
		size_t	my_test;
		char	*first;
		char	*second;
		size_t	n;
		int		length;
		char	*origin1;
		char	*origin2;
		char	*mine1;
		char	*mine2;
		int	n1;
		int	n2;

		first = av[1];
		second = av[2];
		n1 = ft_strlen(av[1]);
		n2 = ft_strlen(av[2]);
		length = n1 + n2;
		n = (size_t)atoi(av[3]);
		mine1 = (char *)malloc(1 + sizeof(char) * length);
		mine2 = (char *)malloc(1 + sizeof(char) * n2);
		origin1 = (char *)malloc(1 + sizeof(char) * length);
		origin2 = (char *)malloc(1 + sizeof(char) * n2);
		mine1 = strcpy(mine1, av[1]);
		mine2 = strcpy(mine2, av[2]);
		origin1 = strcpy(origin1, av[1]);
		origin2 = strcpy(origin2, av[2]);
		origin_test = strlcat(origin1, origin2, n);
		my_test = ft_strlcat(mine1, mine2, n);
		printf("You typed \"%s\", ", first);
		printf("\"%s\", ", second);
		printf("\"%zu\".\n", n);
		printf("Original result is \"%s\" and \"%zu\".\n", origin1, origin_test);
		printf("Your result is \"%s\" and \"%zu\".", mine1, my_test);
	}
	return (0);
}
*/