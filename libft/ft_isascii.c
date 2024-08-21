/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:58:06 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 13:57:39 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this ft judege n is normal ascii
//return 1 : n is normal ascii
//return 0 : n is not normal ascii
int	ft_isascii(int n)
{
	if (n >= 0 && n < 128)
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
		printf("Origin is %d\n", isascii(av[1][0]));
		printf("Mine is %d\n", ft_isascii(av[1][0]));
	}
	return (0);
}
*/