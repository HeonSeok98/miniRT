/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_component_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:23:23 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 13:55:03 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info.h"

void	common_error(char *str);
int		get_digit(int n);
void	throw_w_sp(char **line, int flag);
double	set_coord(char **line, int flag);
double	set_rgb(char **line, int flag);
float	set_ratio(char **line);

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

void	set_l(char *line, t_info *in)
{
	t_l	*l;

	if (in->flag_l)
		in->flag_l = 0;
	else
		common_error("Error\nWe don't need more L\n");
	l = in->l;
	l->next = 0;
	l->prev = 0;
	throw_w_sp(&line, 1);
	if (*line)
	{
		l->position[X] = set_coord(&line, 0);
		l->position[Y] = set_coord(&line, 0);
		l->position[Z] = set_coord(&line, 1);
		throw_w_sp(&line, 1);
		l->bright = set_ratio(&line);
		throw_w_sp(&line, 1);
		l->rgb[R] = set_rgb(&line, 0);
		l->rgb[G] = set_rgb(&line, 0);
		l->rgb[B] = set_rgb(&line, 1);
	}
	else
		common_error("Error\nSomething wrong with L\n");
}
