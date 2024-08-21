/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:30:17 by klha              #+#    #+#             */
/*   Updated: 2023/12/18 20:40:10 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *src)
{
	char	*result;
	char	*temp;

	if (!src)
		return (0);
	result = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!result)
		return (0);
	temp = result;
	while (*src)
		*temp++ = *src++;
	*temp = '\0';
	return (result);
}
