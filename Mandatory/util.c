/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:06:12 by klha              #+#    #+#             */
/*   Updated: 2024/04/03 15:44:01 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include <math.h>

int		get_digit(int n);

//this fucntion skipping white space 
//flag = 0 : all
//flag = 1 : except \n
void	throw_w_sp(char **line, int flag)
{
	if (flag)
	{
		while ((**line >= 11 && **line <= 13) || **line == 32 || **line == 9)
			(*line)++;
	}
	else
	{
		while ((**line >= 9 && **line <= 13) || **line == 32)
			(*line)++;
	}
}

//broadcast error message to fd 2
//and exit by 1.
void	common_error(char *str)
{
	ft_printf_fd(2, "%s", str);
	exit(1);
}

//this ft defense malloc fail
void	*malloc_guard(void *ptr)
{
	if (!ptr)
		common_error("malloc failed!  program terminated!\n");
	return (ptr);
}

//only check for ','
//flag = 1 : last
//flag = 0 : not last
void	check_rest(char **line, int flag)
{
	if (flag)
	{
		if ((**line == 9 || (**line >= 11 && **line <= 13)) || **line == 32)
			return ;
		else
			common_error("Error\ncheckout end of normal vector\n");
	}
	else
	{
		if (**line == ',')
			(*line)++;
		else
			common_error("Error\ncheckout normal vector\n");
	}
}

double	radian(double x)
{
	return (x * M_PI / 180);
}
