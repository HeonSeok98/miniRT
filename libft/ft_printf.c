/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:03:23 by klha              #+#    #+#             */
/*   Updated: 2023/12/18 20:52:04 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	take_hex(va_list ap, const char format)
{
	char			*number;
	int				temp;
	int				result;

	temp = 0;
	if (format == 'x' || format == 'X')
		number = ft_put_hex(va_arg(ap, unsigned int), format);
	else
		number = ft_put_ptr(va_arg(ap, void *));
	if (!number)
		return (-1);
	if (format == 'p')
	{
		temp = printf_putstr_fd("0x", 1);
		if (temp < 0)
		{
			free(number);
			return (-1);
		}
	}
	result = printf_putstr_fd(number, 1);
	free(number);
	if (result < 0)
		return (-1);
	return (result + temp);
}

static int	take_int(va_list ap, const char format)
{
	int				i;
	int				result;
	unsigned int	ui;

	if (format == 'd' || format == 'i')
	{
		i = va_arg(ap, int);
		result = printf_putnbr_fd(i, 1);
	}
	else
	{
		ui = va_arg(ap, unsigned int);
		result = ft_put_unnbr_fd(ui, 1);
	}
	if (result < 0)
		return (-1);
	return (result);
}

static int	take_char(va_list ap, const char *format)
{
	char	c;
	char	*str;

	if (*format == '%')
		return (printf_putchar_fd(*format, 1));
	else if (*format == 'c')
	{
		c = (char)va_arg(ap, int);
		return (printf_putchar_fd(c, 1));
	}
	else
	{
		str = va_arg(ap, char *);
		return (printf_putstr_fd(str, 1));
	}
}

static int	categorize(va_list ap, const char *str)
{
	int	temp;

	temp = 0;
	if (*str == '%' || *str == 'c' || *str == 's')
		temp = take_char(ap, str);
	else if (*str == 'x' || *str == 'X' || *str == 'p')
		temp = take_hex(ap, *str);
	else if (*str == 'i' || *str == 'u' || *str == 'd')
		temp = take_int(ap, *str);
	if (temp < 0)
		return (-1);
	return (temp);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		temp;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			temp = categorize(ap, ++str);
		else
			temp = printf_putchar_fd(*str, 1);
		if (temp < 0)
		{
			va_end(ap);
			return (-1);
		}
		else
			i += temp;
		if (i < 0)
			return (-1);
		str++;
	}
	va_end(ap);
	return (i);
}
