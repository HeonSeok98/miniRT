/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:05:21 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 20:37:36 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int _value, size_t size)
{
	unsigned char	value;
	unsigned char	*temp;

	value = (unsigned char)_value;
	temp = (unsigned char *)ptr;
	while (size--)
		*temp++ = value;
	return (ptr);
}
