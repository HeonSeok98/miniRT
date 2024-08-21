/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_component_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:19:55 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 13:54:40 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info.h"

void	common_error(char *str);
int		get_digit(int n);
double	set_rgb(char **line, int flag);
void	throw_w_sp(char **line, int flag);
void	check_ret(float *ret, int zero_cnt);

static float	set_decimal(char **line)
{
	int		zero_cnt;
	int		temp;
	float	ret;
	int		i;

	zero_cnt = 0;
	i = -1;
	while (**line == '0')
	{
		(*line)++;
		zero_cnt++;
	}
	temp = ft_atoi(*line);
	ret = (float) temp;
	if (temp)
		(*line) += get_digit(temp);
	check_ret(&ret, zero_cnt);
	while (++i < zero_cnt)
		ret /= 10;
	throw_w_sp(line, 0);
	if (!**line)
		common_error("Error\nWe need RGB\n");
	return (ret);
}

static void	set_one(char **line)
{
	if (**line)
	{
		if (**line == '.')
		{
			(*line)++;
			if (**line == '0')
				(*line)++;
			else
				common_error("Error\nSomething wrong\n");
		}
		else if ((**line >= 9 && **line <= 13) || **line == 32)
			return ;
		else
			common_error("Error\nSomething wrong\n");
		throw_w_sp(line, 0);
	}
	if (!**line)
		common_error("Error\nWe need RGB\n");
}

static void	set_ret(char **line, float *ret, int flag)
{
	(*line)++;
	if (flag)
	{
		set_one(line);
		*ret = 1;
	}
	else
	{
		if (ft_isdigit(**line))
			*ret = set_decimal(line);
		else
			common_error("Error\nCheck out bright ratio\n");
	}
}

float	set_ratio(char **line)
{
	float	ret;

	ret = 0;
	if (**line)
	{
		if (**line == '1')
			set_ret(line, &ret, 1);
		else if (**line == '0')
		{
			(*line)++;
			throw_w_sp(line, 1);
			if (**line && **line != '.')
				return (0);
			else if (**line == '.')
				set_ret(line, &ret, 0);
			else
				common_error("Error\nCheck out bright ratio\n");
		}
		else
			common_error("Error\nCheck out bright ratio\n");
	}
	else
		common_error("Error\nCheck bright ratio\n");
	return (ret);
}

void	set_a(char *line, t_info *in)
{
	if (in->flag_a)
		in->flag_a = 0;
	else
		common_error("Error\nWe don't need more A\n");
	throw_w_sp(&line, 0);
	if (*line)
	{
		in->a->ratio = set_ratio(&line);
		throw_w_sp(&line, 1);
		in->a->rgb[R] = set_rgb(&line, 0);
		in->a->rgb[G] = set_rgb(&line, 0);
		in->a->rgb[B] = set_rgb(&line, 1);
	}
	else
		common_error("Error\nSomething wrong with A\n");
}
