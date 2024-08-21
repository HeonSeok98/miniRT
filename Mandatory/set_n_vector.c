/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_n_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:29:11 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 13:55:14 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
//  #include <stdio.h>

void	throw_w_sp(char **line, int flag);
void	common_error(char *str);
void	check_rest(char **line, int flag);
void	check_decimal(double *ret, int zero_cnt);

static double	ret_n(char **line, int flag)
{
	double	n;
	int		zero_cnt;
	int		i;

	if (!ft_isdigit(**line))
		common_error("Error\ncheckout normal vector\n");
	zero_cnt = 0;
	i = -1;
	while (**line == '0')
	{
		(*line)++;
		zero_cnt++;
	}
	n = (double) ft_atoi(*line);
	check_decimal(&n, zero_cnt);
	while (++i < zero_cnt)
		n /= 10;
	while (ft_isdigit(**line))
		(*line)++;
	check_rest(line, flag);
	return (n);
}

static double	ret_zero(int flag)
{
	if (!flag)
		common_error("Error\ncheckout normal vector\n");
	return (0);
}

//result is must be 1 or 1.0
//flag = 1 : last
//flag = 0 : not last
static double	set_one(char **line, int flag)
{
	if ((**line == 9 || (**line >= 11 && **line <= 13)) || **line == 32)
	{
		if (!flag)
			common_error("Error\ncheckout end of normal vector\n");
	}
	else if (**line == '.')
	{
		(*line)++;
		if (**line == '0')
		{
			(*line)++;
			check_rest(line, flag);
		}
		else
			common_error("Error\ncheckout normal vector\n");
	}
	else if (**line == ',')
	{
		if (flag)
			common_error("Error\ncheckout end of normal vector\n");
		(*line)++;
	}
	else
		common_error("Error\ncheckout normal vector\n");
	return (1);
}

//set ratio for A
// first = 1 : Maximum given. it should be white space followed
// first = 0 : normal maximum
//flag = 1 : last
//flag = 0 : not last 
static double	set_ret(char **line, int first, int flag)
{
	if (first)
		return (set_one(line, flag));
	else
	{
		if (**line == ',')
		{
			(*line)++;
			return (0);
		}
		else if ((**line >= 9 && **line <= 13) || **line == 32)
			return (ret_zero(flag));
		else if (**line == '.')
		{
			(*line)++;
			return (ret_n(line, flag));
		}
	}
	common_error("Error\ncheckout normal vector\n");
	return (0);
}

//flag = 1 : last
//flag = 0 : not last
double	set_n_v(char **line, int flag)
{
	double	sign;

	sign = 1;
	if (**line == '-')
	{
		(*line)++;
		sign = -1;
	}
	if (**line == '1')
	{
		(*line)++;
		return (set_ret(line, 1, flag) * sign);
	}
	else if (**line == '0')
	{
		(*line)++;
		return (set_ret(line, 0, flag) * sign);
	}
	else
		common_error("Error\nplease check on normal vector\n");
	return (0);
}
