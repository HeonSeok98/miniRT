/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:13:06 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 21:13:07 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src);

char	*set_number(int n, int digit, int sign)
{
	char	*number;

	number = (char *)malloc(1 + sizeof(char) * digit);
	if (!number)
		return (0);
	number[digit--] = '\0';
	if (n == 0)
		number[0] = '0';
	else
	{
		while (n > 0)
		{
			number[digit--] = (n % 10) + '0';
			n /= 10;
		}
	}
	if (sign)
		number[0] = '-';
	return (number);
}

int	get_digit(int n)
{
	int	digit;

	digit = 1;
	while (n > 9)
	{
		digit++;
		n /= 10;
	}	
	return (digit);
}

char	*ft_itoa(int n)
{
	int		digit;
	int		sign;

	digit = 0;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		digit++;
		n *= -1;
		sign++;
	}
	digit += get_digit(n);
	return (set_number(n, digit, sign));
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("You typed \'%s\'\n", av[1]);
		//char *test;
		int n = atoi(av[1]);
		//printf("Origin is %d\n", itoa(n, test, 10));
		printf("Mine is %s\n", ft_itoa(n));
	}
	return (0);
}
*/