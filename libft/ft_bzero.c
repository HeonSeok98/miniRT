/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:38:05 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 20:43:32 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int _value, size_t size);

void	ft_bzero(void *str, size_t len)
{
	str = ft_memset(str, 0, len);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[10] = "123456789";
	printf("%s\n", str);
	ft_bzero(str,1);
	for (int i = 0; i < 10; i++)
		printf("%c", str[i]);
}
*/