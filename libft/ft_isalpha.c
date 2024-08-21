/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:44:27 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 13:55:10 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this ft judge n is alphabet or not
//but this not judge n is uppercase or lowercase
//return 1 : n is alphabet
//return 0 : n is not alphabet
int	ft_isalpha(int n)
{
	if (n >= 'A' && n <= 'Z')
		return (1);
	else if (n >= 'a' && n <= 'z')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("You typed \'%s\'\n", av[1]);
		printf("Origin is %d\n", isalpha(av[1][0]));
		printf("Mine is %d\n", ft_isalpha(av[1][0]));
	}
	return (0);
}
*/