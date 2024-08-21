/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_component_obj_1_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:05:09 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 19:01:15 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"

void	common_error(char *str);
double	set_coord(char **line, int flag);
void	throw_w_sp(char **line, int flag);
double	make_ret(char **line, int sign);
double	set_n_v(char **line, int flag);
int		get_digit(int n);
double	set_double(char **line);
void	check_dir(double *dir);

//return rgb ranged int
//flag = 1 : last b 
//flag = 0 : r or g
double	set_rgb(char **line, int flag)
{
	double	temp;

	if (!ft_isdigit(**line))
		common_error("Error\nRGB should start number!\n");
	temp = (double) ft_atoi(*line);
	if (temp < 0 || temp > 255)
		common_error("Error\nimproper color RGB\n");
	while (ft_isdigit(**line))
		(*line)++;
	if (flag)
	{
		throw_w_sp(line, 0);
		if (**line)
			common_error("Error\nplease cheack end of RGB!\n");
		else
			return (temp / 255);
	}
	if (**line != ',')
		common_error("Error\nWhere is ,??\n");
	else
		(*line)++;
	return (temp / 255);
}

double	set_double(char **line)
{
	int		sign;
	double	ret;

	sign = 1;
	ret = 0;
	if (**line == '-')
	{
		(*line)++;
		sign = -1;
	}
	if (ft_isdigit(**line))
	{
		ret = make_ret(line, sign);
		throw_w_sp(line, 0);
		if (!**line)
			common_error("Error\nNot enough infomation\n");
	}
	else
		common_error("Error\nplease check on object's length\n");
	return (ret);
}

void	set_pl(char *line, t_obj *pla)
{
	pla->type = pl;
	pla->cy_h = 0;
	pla->r = 0;
	if (*line == '-' || ft_isdigit(*line))
	{
		pla->position[X] = set_coord(&line, 0);
		pla->position[Y] = set_coord(&line, 0);
		pla->position[Z] = set_coord(&line, 1);
		throw_w_sp(&line, 1);
		pla->n_v[X] = set_n_v(&line, 0);
		pla->n_v[Y] = set_n_v(&line, 0);
		pla->n_v[Z] = set_n_v(&line, 1);
		check_dir(pla->n_v);
		throw_w_sp(&line, 1);
		pla->rgb[R] = set_rgb(&line, 0);
		pla->rgb[G] = set_rgb(&line, 0);
		pla->rgb[B] = set_rgb(&line, 1);
	}
	else
		common_error("Error\nSomething wrong with sphere\n");
}

void	set_cy(char *line, t_obj *cyl)
{
	cyl->type = cy;
	if (*line == '-' || ft_isdigit(*line))
	{
		cyl->position[X] = set_coord(&line, 0);
		cyl->position[Y] = set_coord(&line, 0);
		cyl->position[Z] = set_coord(&line, 1);
		throw_w_sp(&line, 1);
		cyl->n_v[X] = set_n_v(&line, 0);
		cyl->n_v[Y] = set_n_v(&line, 0);
		cyl->n_v[Z] = set_n_v(&line, 1);
		check_dir(cyl->n_v);
		throw_w_sp(&line, 1);
		cyl->r = set_double(&line);
		cyl->cy_h = set_double(&line);
		if (cyl->r <= 0 || cyl->cy_h <= 0)
			common_error("Error\nlength should be bigger than 0\n");
		cyl->rgb[R] = set_rgb(&line, 0);
		cyl->rgb[G] = set_rgb(&line, 0);
		cyl->rgb[B] = set_rgb(&line, 1);
	}
	else
		common_error("Error\nSomething wrong with sphere\n");
}

void	set_sp(char *line, t_obj *sph)
{
	sph->type = sp;
	sph->n_v[X] = 0;
	sph->n_v[Y] = 0;
	sph->n_v[Z] = 0;
	sph->cy_h = 0;
	if (*line == '-' || ft_isdigit(*line))
	{
		sph->position[X] = set_coord(&line, 0);
		sph->position[Y] = set_coord(&line, 0);
		sph->position[Z] = set_coord(&line, 1);
		throw_w_sp(&line, 1);
		sph->r = set_double(&line);
		if (sph->r <= 0)
			common_error("Error\nDiameter is below than 0\n");
		sph->rgb[R] = set_rgb(&line, 0);
		sph->rgb[G] = set_rgb(&line, 0);
		sph->rgb[B] = set_rgb(&line, 1);
	}
	else
		common_error("Error\nSomething wrong with sphere\n");
}
