/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:12:26 by klha              #+#    #+#             */
/*   Updated: 2023/10/09 21:12:29 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*temp;
	size_t	n;

	n = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(1 + sizeof(char) * n);
	if (!str)
		return (0);
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char *str = ft_strjoin(av[1],av[2])
		printf("You typed \"%s\" and \"%s\".\nResult is \"%s\"", av[1], av[2],str);
		free(str);
	}	
	return (0);
}
*/