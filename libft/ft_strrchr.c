/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:24:57 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 16:27:33 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*string;
	char	n;

	n = (char)c;
	string = (char *)str;
	if (!*string && n != 0)
		return (0);
	while (*string)
		string++;
	if (!n)
		return (string);
	string--;
	while (str != string)
	{
		if (*string == n)
			return (string);
		string--;
	}
	if (*string == n)
		return (string);
	return (0);
}
/*
 *	strrchr(const char *str, int n)
 *
 *  find specific character for the first time in backward.
 *	str : target string to find
 *  n : char that we want to find 
 
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	*origin;
		char	*mine;

		mine = ft_strrchr(av[1], av[2][0]);
		origin = strrchr(av[1], av[2][0]);
		printf("You typed \"%s\" and \"%c\".\n", av[1], av[2][0]);
		if (origin)
			printf("Original result is \"Located\" and \"%s\".\n", origin);
		else
			printf("Original result is \"Not located\".\n");
		if (mine)
			printf("My result is \"Located\" and \"%s\".\n", mine);
		else
			printf("My result is \"Not located\".\n");
	}
	return (0);
}
*/
