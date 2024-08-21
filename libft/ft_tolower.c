/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:16:02 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 18:20:58 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int n)
{
	unsigned char	c;

	c = (unsigned char) n;
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (n);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	result = ft_tolower(av[1][0]);
		char	std = tolower(av[1][0]);
		printf("You typed \"%c\".\n", av[1][0]);
		printf("Origin is \"%c\".\n", std);
		printf("Your result is \"%c\".\n", result);
		printf("Original \"-1\" result is \"%d\".\n", tolower(-1));
		printf("Your \"-1\" result is \"%d\".\n", ft_tolower(-1));
		printf("Original \"EOF\" result is \"%d\".\n", tolower(EOF));
		printf("Your \"EOF\" result is \"%d\".\n", ft_tolower(EOF));
	}
	return (0);
}
*/