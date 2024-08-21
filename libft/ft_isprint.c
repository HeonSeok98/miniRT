/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:18 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 13:56:52 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this ft judge n is printable
//return 1 : n is printable
//return 0 : n is not printable
int	ft_isprint(int n)
{
	if (n >= 32 && n <= 126)
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
		printf("Origin is %d\n", isprint(av[1][0]));
		printf("Mine is %d\n", ft_isprint(av[1][0]));
	}
	return (0);
}
*/