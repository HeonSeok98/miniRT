/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:12:26 by klha              #+#    #+#             */
/*   Updated: 2023/12/18 20:49:50 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	printf_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	printf_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

static int	get_digit(unsigned int n, unsigned int base)
{
	int	digit;

	digit = 1;
	if (base < 2)
		return (-1);
	while (n > base - 1)
	{
		digit++;
		n /= base;
	}
	return (digit);
}

char	*ft_put_ptr(void *ptr)
{
	char		*base;
	char		*number;
	int			digit;
	uintptr_t	n;

	base = "0123456789abcdef";
	n = (uintptr_t)ptr;
	digit = 1;
	while (n > 15)
	{
		digit++;
		n /= 16;
	}
	n = (uintptr_t)ptr;
	number = (char *)malloc(sizeof(char) * (digit + 1));
	if (!number)
		return (0);
	number[digit--] = '\0';
	while (digit > -1)
	{
		number[digit--] = base[n % 16];
		n /= 16;
	}
	return (number);
}

char	*ft_put_hex(unsigned int n, char det)
{
	char	*base;
	char	*number;
	int		digit;

	if (det == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	digit = get_digit(n, 16);
	number = (char *)malloc(sizeof(char) * (digit + 1));
	if (!number)
		return (0);
	number[digit--] = '\0';
	while (digit > -1)
	{
		number[digit--] = base[n % 16];
		n /= 16;
	}
	return (number);
}
