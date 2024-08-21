/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:54:05 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 13:54:02 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int n);

int	ft_isdigit(int n);

//this ft is judge n is alnum or not
//return 1 : n is alnum
//return 0 : n is not alnum
int	ft_isalnum(int n)
{
	if (ft_isalpha(n) || ft_isdigit(n))
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
		printf("Origin is %d\n", isalnum(av[1][0]));
		printf("Mine is %d\n", ft_isalnum(av[1][0]));
	}
	return (0);
}
*/