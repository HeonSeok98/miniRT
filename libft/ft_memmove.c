/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:06:33 by klha              #+#    #+#             */
/*   Updated: 2023/10/06 21:33:47 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*changed_dest;
	unsigned char	*changed_src;
	unsigned int	i;

	if (!dest && !src)
		return (0);
	changed_src = (unsigned char *)src;
	changed_dest = (unsigned char *)dest;
	i = 0;
	if (changed_dest < changed_src)
	{
		while (i < len)
		{
			changed_dest[i] = changed_src[i];
			i++;
		}
	}
	else if (changed_dest > changed_src)
	{
		while (len-- > 0)
			changed_dest[len] = changed_src[len];
	}
	return (dest);
}
