/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:34:31 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 14:04:29 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//this ft judge s1, s2 are same str
//return 0 : s1 and s2 is same str
//return non_zero : they are different str
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*changed_s1;
	unsigned char	*changed_s2;

	changed_s1 = (unsigned char *)s1;
	changed_s2 = (unsigned char *)s2;
	while ((*changed_s1 || *changed_s2))
	{
		if (*changed_s1 > *changed_s2)
			return (1);
		else if (*changed_s1 < *changed_s2)
			return (-1);
		changed_s1++;
		changed_s2++;
	}
	if ((!*changed_s1 && *changed_s2)
		|| (*changed_s1 && !*changed_s2))
		return (1);
	return (0);
}

//this ft judge s1 and s2 are same str under limited length n.
//return 0 : s1 and s2 is same str until n
//return non_zero : they are different str
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*changed_s1;
	unsigned char	*changed_s2;

	i = 0;
	changed_s1 = (unsigned char *)s1;
	changed_s2 = (unsigned char *)s2;
	while ((*changed_s1 || *changed_s2) && i < n)
	{
		if (*changed_s1 > *changed_s2)
			return (1);
		else if (*changed_s1 < *changed_s2)
			return (-1);
		changed_s1++;
		changed_s2++;
		i++;
	}
	return (0);
}
/*
 strncmp (const char *str1, const char *str2, unsigned n)
 	criteria base is it's ASCII code until index n
	1) str1 == str2
 		return (0);
	2) str1 < str2
		return (negative) because str1 - str2 < 0
	3) str1 > str2
		return (positive) because str1 - str2 > 0

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("Original result is \"%d\".\n", strncmp("abcd", "abae", 5));
	printf("Your result is \"%d\".\n", ft_strncmp("abcd", "abae", 5));
	return (0);
}
 */