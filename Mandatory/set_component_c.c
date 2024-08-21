/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_component_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:00:19 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 17:56:42 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info.h"

void	common_error(char *str);
int		get_digit(int n);
void	check_dir(double *dir);
void	throw_w_sp(char **line, int flag);
double	set_coord(char **line, int flag);
double	set_n_v(char **line, int flag);

int	set_fov(char **line)
{
	long	fov;

	if (!ft_isdigit(**line))
		common_error("Error\nWe need FOV for C\n");
	fov = ft_atol(*line);
	if (fov < 0 || fov > 180)
		common_error("Error\nOut of range of FOV for C\n");
	while (ft_isdigit(**line))
		(*line)++;
	throw_w_sp(line, 0);
	if (**line)
		common_error("Error\nWe don't need anymore for C\n");
	return ((int) fov);
}

void	set_c(char *line, t_info *in)
{
	t_c	*c;

	if (in->flag_c)
		in->flag_c = 0;
	else
		common_error("Error\nWe don't need more C\n");
	c = in->c;
	throw_w_sp(&line, 1);
	if (*line)
	{
		c->position[X] = set_coord(&line, 0);
		c->position[Y] = set_coord(&line, 0);
		c->position[Z] = set_coord(&line, 1);
		throw_w_sp(&line, 1);
		c->n_v[X] = set_n_v(&line, 0);
		c->n_v[Y] = set_n_v(&line, 0);
		c->n_v[Z] = set_n_v(&line, 1);
		check_dir(c->n_v);
		throw_w_sp(&line, 1);
		c->fov = set_fov(&line);
	}
	else
		common_error("Error\nSomething wrong with C\n");
}
