/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolee <heolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:07:41 by heolee            #+#    #+#             */
/*   Updated: 2024/04/05 15:07:42 by heolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

// void	bump_map(t_hit_record *rec)
// {
// 	double	tmp;
// 	double	unit;

// 	unit = 32767000000.0;
// 	tmp = (double)rand() / unit;
// 	rec->n_v[X] += tmp;
// 	tmp = (double)rand() / unit;
// 	rec->n_v[Y] += tmp;
// 	tmp = (double)rand() / unit;
// 	rec->n_v[Z] += tmp;
// }

void	sphere_bumpmap(t_obj *obj, t_hit_record *rec)
{
	double	u;
	double	v;
	int		int_u;
	int		int_v;

	u = 1 - ((atan2(rec->n_v[X], rec->n_v[Z]) / (2 * M_PI)) + 0.5);
	v = 1 - (acos(rec->n_v[Y] / (obj->r / 2)) / M_PI);
	int_u = (int)(u * 60);
	int_v = (int)(v * 60);
	rec->n_v[X] = obj->bump[int_v][int_u][X] * 2 - 1;
	rec->n_v[Y] = obj->bump[int_v][int_u][Y] * 2 - 1;
	rec->n_v[Z] = obj->bump[int_v][int_u][Z] * 2 - 1;
	vec_unit(rec->n_v);
}

void	plane_bumpmap(t_obj *obj, t_hit_record *rec)
{
	double	u;
	double	v;
	int		int_u;
	int		int_v;

	if (obj->n_v[X] < EPSILON && obj->n_v[Y] < EPSILON)
	{
		u = fabs(fmod(rec->pos[X], 1.0));
		v = fabs(fmod(rec->pos[Y], 1.0));
	}
	else
	{
		u = fabs(fmod(rec->pos[X], 1.0));
		v = fabs(fmod(rec->pos[Z], 1.0));
	}
	int_u = (int)(u * 60);
	int_v = (int)(v * 60);
	rec->n_v[X] = obj->bump[int_v][int_u][X] * 2 - 1;
	rec->n_v[Y] = obj->bump[int_v][int_u][Y] * 2 - 1;
	rec->n_v[Z] = obj->bump[int_v][int_u][Z] * 2 - 1;
	vec_unit(rec->n_v);
}

void	cylinder_side_bumpmap(t_obj *obj, t_hit_record *rec)
{
	double	u;
	double	v;
	int		int_u;
	int		int_v;

	if (fabs(obj->n_v[X]) < fabs(obj->n_v[Y]))
	{
		u = 1 - ((atan2(rec->n_v[X], rec->n_v[Z]) / (2 * M_PI)) + 0.5);
		v = fabs(fmod(rec->pos[Y], 1.0));
	}
	else
	{
		u = 1 - ((atan2(rec->n_v[Y], rec->n_v[Z]) / (2 * M_PI)) + 0.5);
		v = fabs(fmod(rec->pos[X], 1.0));
	}
	int_u = (int)(u * 60);
	int_v = (int)(v * 60);
	rec->n_v[X] = obj->bump[int_v][int_u][X] * 2 - 1;
	rec->n_v[Y] = obj->bump[int_v][int_u][Y] * 2 - 1;
	rec->n_v[Z] = obj->bump[int_v][int_u][Z] * 2 - 1;
	vec_unit(rec->n_v);
}

void	bump_map(t_obj *obj, t_hit_record *rec, int flag)
{
	if (obj->type == sp)
		sphere_bumpmap(obj, rec);
	else if (obj->type == pl)
		plane_bumpmap(obj, rec);
	else if (obj->type == cn)
		cylinder_side_bumpmap(obj, rec);
	else if (obj->type == cy)
	{
		if (flag)
			cylinder_side_bumpmap(obj, rec);
		else
			plane_bumpmap(obj, rec);
	}
}
