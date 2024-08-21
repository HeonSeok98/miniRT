/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:51:30 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 13:56:23 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this ft judge n is number
//return 1 : n is number
//return 0 : n is not number
int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
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
		printf("Origin is %d\n", isdigit(av[1][0]));
		printf("Mine is %d\n", ft_isdigit(av[1][0]));
	}
	return (0);
}
*/