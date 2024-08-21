/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coord_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:03:55 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 17:04:19 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	throw_w_sp(char **line, int flag);
void	common_error(char *str);
int		get_digit(int n);
double	set_double(char **line);
void	check_double(double n);
void	decimal_cnt(int	*cnt);

void	make_temp_d(double *temp_d, char **line)
{
	int		cnt;

	cnt = 0;
	while (*temp_d >= 1)
	{
		*temp_d /= 10;
		decimal_cnt(&cnt);
	}
	while (**line == '0')
	{
		(*line)++;
		*temp_d /= 10;
		decimal_cnt(&cnt);
	}
}

//make double number
//line : it should be start with number
//it doesn't test end of str!! be careful
double	make_ret(char **line, int sign)
{
	double	ret;
	double	temp_d;

	ret = (double) ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	if (**line == '.')
	{
		(*line)++;
		if (!ft_isdigit(**line))
			common_error("Error\nplease check on coordinate\n");
		temp_d = (double) ft_atoi(*line);
		make_temp_d(&temp_d, line);
		while (ft_isdigit(**line))
			(*line)++;
		ret += temp_d;
	}
	check_double(ret);
	return (ret * sign);
}

//flag = 1 : last
//flag = 0 : not last
double	set_coord(char **line, int flag)
{
	int		sign;
	double	ret;

	sign = 1;
	if (**line == '-')
	{
		(*line)++;
		sign = -1;
	}
	if (!ft_isdigit(**line))
		common_error("Error\nplease check on number\n");
	ret = make_ret(line, sign);
	if (flag)
	{
		if (!((**line == 9 || (**line >= 11 && **line <= 13)) || **line == 32))
			common_error("Error\nplease check on end of number\n");
	}
	else
	{
		if (**line != ',')
			common_error("Error\nplease check on number\n");
		(*line)++;
	}
	return (ret);
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return 1;
// 	int sign = 1;
// 	if (*av[1] == '-')
// 	{
// 		av[1]++;
// 		sign = -1;
// 	}
// 	printf("result is %lf", make_ret(&av[1], sign));
// 	return 0;
// }