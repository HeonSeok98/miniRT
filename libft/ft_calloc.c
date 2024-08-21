/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:38:16 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 13:55:40 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len);

//this ft malloc count * size and reset all of memery inside to 0
void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	n;

	n = size * count;
	temp = malloc(n);
	if (!temp)
		return (0);
	ft_bzero(temp, n);
	return (temp);
}
/*
#include <stdio.h>

int	main(void)
{
	int *mal;
	int	*cal;

	mal = (int *)malloc(sizeof(int) * 00);
	cal = (int *)ft_calloc(sizeof(int) * 10, sizeof(int) * 100);

	for (int i = 0; i < 10; i++)
		printf("mal = %d\t\t\t\tcal = %d\n", mal[i], cal[i]);
	free(mal);
	free(cal);
}
*/