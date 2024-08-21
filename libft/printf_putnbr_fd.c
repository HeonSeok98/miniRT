/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:16:23 by klha              #+#    #+#             */
/*   Updated: 2023/12/18 20:54:28 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	over_ten_ui(unsigned int n, int fd)
{
	int	temp1;
	int	temp2;

	temp1 = ft_put_unnbr_fd(n / 10, fd);
	if (temp1 < 0)
		return (-1);
	temp2 = ft_put_unnbr_fd(n % 10, fd);
	if (temp2 < 0)
		return (-1);
	return (temp1 + temp2);
}

int	ft_put_unnbr_fd(unsigned int n, int fd)
{
	char	c;
	int		temp;

	c = '0';
	if (n > 9)
		temp = over_ten_ui(n, fd);
	else
	{
		c += n;
		temp = printf_putchar_fd(c, fd);
	}
	if (temp < 0)
		return (-1);
	return (temp);
}

static int	over_ten(int n, int fd)
{
	int	temp1;
	int	temp2;

	temp1 = printf_putnbr_fd(n / 10, fd);
	if (temp1 < 0)
		return (-1);
	temp2 = printf_putnbr_fd(n % 10, fd);
	if (temp2 < 0)
		return (-1);
	return (temp1 + temp2);
}

static int	meet_negative(int n, int fd)
{
	int	temp;

	temp = printf_putchar_fd('-', fd);
	if (temp < 0)
		return (-1);
	n *= -1;
	temp = printf_putnbr_fd(n, fd);
	if (temp < 0)
		return (-1);
	return (temp + 1);
}

int	printf_putnbr_fd(int n, int fd)
{
	char	c;
	int		temp;

	c = '0';
	if (n == -2147483648)
		temp = printf_putstr_fd("-2147483648", fd);
	else if (n < 0)
		temp = meet_negative(n, fd);
	else if (n > 9)
		temp = over_ten(n, fd);
	else
	{
		c += n;
		temp = printf_putchar_fd(c, fd);
	}
	if (temp < 0)
		return (-1);
	return (temp);
}
