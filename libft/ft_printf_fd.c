/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:03:23 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 15:19:50 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	take_hex(va_list ap, const char format, int fd)
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
		temp = printf_putstr_fd("0x", fd);
		if (temp < 0)
		{
			free(number);
			return (-1);
		}
	}
	result = printf_putstr_fd(number, fd);
	free(number);
	if (result < 0)
		return (-1);
	return (result + temp);
}

static int	take_int(va_list ap, const char format, int fd)
{
	int				i;
	int				result;
	unsigned int	ui;

	if (format == 'd' || format == 'i')
	{
		i = va_arg(ap, int);
		result = printf_putnbr_fd(i, fd);
	}
	else
	{
		ui = va_arg(ap, unsigned int);
		result = ft_put_unnbr_fd(ui, fd);
	}
	if (result < 0)
		return (-1);
	return (result);
}

static int	take_char(va_list ap, const char *format, int fd)
{
	char	c;
	char	*str;

	if (*format == '%')
		return (printf_putchar_fd(*format, fd));
	else if (*format == 'c')
	{
		c = (char)va_arg(ap, int);
		return (printf_putchar_fd(c, fd));
	}
	else
	{
		str = va_arg(ap, char *);
		return (printf_putstr_fd(str, fd));
	}
}

static int	categorize(va_list ap, const char *str, int fd)
{
	int	temp;

	temp = 0;
	if (*str == '%' || *str == 'c' || *str == 's')
		temp = take_char(ap, str, fd);
	else if (*str == 'x' || *str == 'X' || *str == 'p')
		temp = take_hex(ap, *str, fd);
	else if (*str == 'i' || *str == 'u' || *str == 'd')
		temp = take_int(ap, *str, fd);
	if (temp < 0)
		return (-1);
	return (temp);
}

//this ft advanced version of ft_printf
//write to given fd not only 1 
int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	ap;
	int		i;
	int		temp;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			temp = categorize(ap, ++str, fd);
		else
			temp = printf_putchar_fd(*str, fd);
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
