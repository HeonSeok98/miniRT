/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:03 by klha              #+#    #+#             */
/*   Updated: 2024/02/07 13:59:39 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);

static void	make_result(va_list ap, char *result, char *str)
{
	char	*temp;

	while (*str)
	{
		if (*str == '%')
		{
			temp = va_arg(ap, char *);
			while (*temp)
			{
				*result = *temp;
				result++;
				temp++;
			}
		}
		else
		{
			*result = *str;
			result++;
		}
		str++;
	}
	*result = 0;
}

static char	*get_result(va_list copy, char *str)
{
	int		n;
	char	*temp;
	char	*result;

	n = 0;
	while (*str)
	{
		if (*str == '%')
		{
			temp = (char *)va_arg(copy, char *);
			n += ft_strlen(temp) - 1;
		}
		str++;
		n++;
	}
	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (0);
	return (result);
}

//this ft make a whole str by given char *args
//usage ex) whole_str = ft_strjoin_all("%_%", "test", "result")
//then whole_str = "test_result"
char	*ft_strjoin_all(char *str, ...)
{
	va_list	ap;
	va_list	copy;
	char	*result;

	if (!str)
		return (0);
	else if (!*str)
		return (ft_calloc(1, sizeof(char)));
	va_start(ap, str);
	va_copy(copy, ap);
	result = get_result(copy, str);
	if (!result)
		return (0);
	make_result(ap, result, str);
	va_end(copy);
	va_end(ap);
	return (result);
}
