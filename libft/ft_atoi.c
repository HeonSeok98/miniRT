/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:35:46 by klha              #+#    #+#             */
/*   Updated: 2024/02/06 19:49:14 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n);

long	ft_atol(const char *str)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}
/*
whitespace = space, \n, \t, \v, \f, \r
		ascii code 9~13 & 32

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("You typed \'%s\'\n", av[1]);
		printf("Origin is %d\n", atoi(av[1]));
		printf("Mine is %d\n", ft_atoi(av[1]));
	}
	return (0);
}
*/