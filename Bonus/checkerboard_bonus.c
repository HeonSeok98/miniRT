/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:22:43 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 19:01:33 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

// void	bump_map(t_hit_record *rec);
void	bump_map(t_obj *obj, t_hit_record *rec, int flag);

void	sphere_checkerboard(t_obj *obj, t_hit_record *rec)
{
	double	theta;
	double	phi;
	double	raw_u;
	double	u;
	double	v;

	theta = atan2(rec->n_v[X], rec->n_v[Z]);
	phi = acos(rec->n_v[Y] / (obj->r / 2));
	raw_u = theta / (2 * M_PI);
	u = 1 - (raw_u + 0.5);
	v = 1 - (phi / M_PI);
	if (((int)floor(u * obj->r * 4) + (int)floor(v * obj->r * 4)) % 2 == 0)
	{
		rec->rgb[X] = 1;
		rec->rgb[Y] = 1;
		rec->rgb[Z] = 1;
	}
	else
		vec_copy(rec->rgb, obj->rgb);
}

void	plane_checkerboard(t_obj *obj, t_hit_record *rec)
{
	double	u;
	double	v;

	if (obj->n_v[X] < EPSILON && obj->n_v[Y] < EPSILON)
	{
		u = fmod(rec->pos[X], 1.0);
		v = fmod(rec->pos[Y], 1.0);
	}
	else
	{
		u = fmod(rec->pos[X], 1.0);
		v = fmod(rec->pos[Z], 1.0);
	}
	if (((int)floor(u * 2) + (int)floor(v * 2)) % 2 == 0)
	{
		rec->rgb[X] = 1;
		rec->rgb[Y] = 1;
		rec->rgb[Z] = 1;
	}
	else
		vec_copy(rec->rgb, obj->rgb);
}

void	cylinder_side_checkerboard(t_obj *obj, t_hit_record *rec)
{
	double	u;
	double	v;

	if (fabs(obj->n_v[X]) < fabs(obj->n_v[Y]))
	{
		u = 1 - ((atan2(rec->n_v[X], rec->n_v[Z]) / (2 * M_PI)) + 0.5);
		v = fmod(rec->pos[Y], 1.0);
	}
	else
	{
		u = 1 - ((atan2(rec->n_v[Y], rec->n_v[Z]) / (2 * M_PI)) + 0.5);
		v = fmod(rec->pos[X], 1.0);
	}
	if (((int)floor(u * 30) + (int)floor(v * 2)) % 2 == 0)
	{
		rec->rgb[X] = 1;
		rec->rgb[Y] = 1;
		rec->rgb[Z] = 1;
	}
	else
		vec_copy(rec->rgb, obj->rgb);
}

void	obj_version(t_obj *obj, t_hit_record *rec, int flag)
{
	if (obj->flag == 0)
		vec_copy(rec->rgb, obj->rgb);
	else if (obj->flag == 1)
	{
		vec_copy(rec->rgb, obj->rgb);
		bump_map(obj, rec, flag);
	}
	else
	{
		if (obj->type == sp)
			sphere_checkerboard(obj, rec);
		else if (obj->type == pl)
			plane_checkerboard(obj, rec);
		else if (obj->type == cn)
			cylinder_side_checkerboard(obj, rec);
		else if (obj->type == cy)
		{
			if (flag)
				cylinder_side_checkerboard(obj, rec);
			else
				plane_checkerboard(obj, rec);
		}
	}
}
