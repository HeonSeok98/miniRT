/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:50:10 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 21:04:59 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*changed_dest;
	unsigned char	*changed_src;

	changed_dest = (unsigned char *)dest;
	changed_src = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	i = 0;
	while (i < len)
	{
		changed_dest[i] = changed_src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	*src;
		int		lenth;
		char	*result;

		src = av[1];
		lenth = atoi(av[2]);
		result = (char *)calloc(lenth + 1, sizeof(char));
		result = (char *)ft_memcpy(result, src, lenth);
		printf("You typed \'%s\' and \'%d\'\n", src, lenth);
		printf("result is \'%s\'\n", result);
		free(result);
		
		int	src2[] = {1, 2, 3};
		int dest[3];

		ft_memcpy(dest, src2, sizeof(int) * 3);
		printf("Origin int arr is {%d, %d, %d}\n", src2[0], src2[1], src2[2]);
		printf("result int arr is {%d, %d, %d}", dest[0], dest[1], dest[2]);
	}
	return (0);
}
*/