/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_component_obj_2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:23:23 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 13:59:07 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include <math.h>

void	common_error(char *str);
double	set_coord(char **line, int flag);
void	throw_w_sp(char **line, int flag);
double	set_n_v(char **line, int flag);
double	set_double(char **line);
void	check_dir(double *dir);
double	radian(double x);
double	set_rgb(char **line, int flag);

void	check_decimal(double *ret, int zero_cnt)
{
	while ((*ret) >= 1)
	{
		zero_cnt++;
		(*ret) /= 10;
		if (zero_cnt > 6)
			common_error("Error\nToo many decimal places!\n");
	}
}

void	check_ret(float *ret, int zero_cnt)
{
	while ((*ret) >= 1)
	{
		zero_cnt++;
		(*ret) /= 10;
		if (zero_cnt > 6)
			common_error("Error\nToo many decimal places!\n");
	}
}

//
void	set_cn(char *line, t_obj *cone)
{
	cone->type = cn;
	if (*line == '-' || ft_isdigit(*line))
	{
		cone->position[X] = set_coord(&line, 0);
		cone->position[Y] = set_coord(&line, 0);
		cone->position[Z] = set_coord(&line, 1);
		throw_w_sp(&line, 1);
		cone->n_v[X] = set_n_v(&line, 0);
		cone->n_v[Y] = set_n_v(&line, 0);
		cone->n_v[Z] = set_n_v(&line, 1);
		check_dir(cone->n_v);
		throw_w_sp(&line, 1);
		cone->cy_h = set_double(&line);
		if (cone->cy_h <= 0 || cone->cy_h >= 90)
			common_error("Error\nsemi cone angle should be acute angle\n");
		cone->r = pow(cos(radian(cone->cy_h)), 2);
		cone->rgb[R] = set_rgb(&line, 0);
		cone->rgb[G] = set_rgb(&line, 0);
		cone->rgb[B] = set_rgb(&line, 1);
	}
	else
		common_error("Error\nSomething wrong with sphere\n");
}
