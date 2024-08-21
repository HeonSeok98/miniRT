/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:13:26 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 21:13:27 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!f || !s)
		return ;
	while (*s)
		f(i++, &*s++);
}
/*
#include <stdio.h>

void	f(unsigned int i, char *a)
{
	printf("\"%d\" and \"%s\".\n", i, a);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("You typed \"%s\".\n", av[1]);
		printf("Result is down below.\n");
		printf("=====================\n");
		ft_striteri(av[1], f);
		printf("=====================\n");
	}
	return (0);
}
*/