/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:58:46 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 16:58:56 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (ft_strlen(src));
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	a;
	int b;
	char *c;

	c = (char *)malloc(sizeof(char) * 4);
	a = strlcpy(c, "aaa", 3);
	b = ft_strlcpy(c, "aaa", 3);
	printf("Original result is %d.\n", a);
	printf("Your result is %d.\n", b);
	free(c);
	c = 0;
	return (0);
}
*/