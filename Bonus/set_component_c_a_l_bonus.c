/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_component_c_a_l_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:00:19 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 20:05:03 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"

void	common_error(char *str);
int		get_digit(int n);
void	check_dir(double *dir);
void	throw_w_sp(char **line, int flag);
double	set_coord(char **line, int flag);
double	set_n_v(char **line, int flag);
double	set_rgb(char **line, int flag);
float	set_ratio(char **line);
void	*malloc_guard(void *ptr);

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

static t_l	*get_last_light(t_info *in)
{
	t_l	*last;

	last = in->l;
	if (in->flag_l)
	{
		in->flag_l = 0;
		last->next = 0;
		last->prev = 0;
		return (last);
	}
	while (last->next)
		last = last->next;
	last->next = (t_l *)malloc_guard(malloc(sizeof(t_l)));
	last->next->next = 0;
	last->next->prev = last;
	return (last->next);
}

void	set_l(char *line, t_info *in)
{
	t_l	*l;

	l = get_last_light(in);
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

static int	set_fov(char **line)
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
