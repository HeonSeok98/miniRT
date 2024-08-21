/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:12:34 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 18:21:42 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int n)
{
	unsigned char	c;

	c = (unsigned char) n;
	if (c >= 'a' && c <= 'z')
		return (n - 'a' + 'A');
	return (n);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	result = ft_toupper(av[1][0]);
		char	std = toupper(av[1][0]);
		printf("You typed \"%c\".\n", av[1][0]);
		printf("Origin is \"%c\".\n", std);
		printf("Your result is \"%c\".\n", result);
		printf("And Original \"-1\" result is \"%d\".\n", toupper(-1));
		printf("Your \"-1\" result is \"%d\".\n", ft_toupper(-1));
		printf("And Original \"EOF\" result is \"%d\".\n", toupper(EOF));
		printf("Your \"EOF\" result is \"%d\".\n", ft_toupper(EOF));
	}
	return (0);
}
*/