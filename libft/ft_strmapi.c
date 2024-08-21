/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:13:16 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 21:13:17 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	str = (char *)malloc(1 + len);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

char	f(unsigned int i, char c)
{
	i = 0;
	if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
		c++;
	else if (c == 'z' || c == 'Z')
		c = c - 'z' + 'a';
	else
		c = '0';
	return (c);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*test;

		test = ft_strmapi(av[1], f);
		printf("You typed \"%s\".\n", av[1]);
		printf("Result is \"%s\".\n", test);
		free(test);
		test = 0;
	}
	return (0);
}
*/