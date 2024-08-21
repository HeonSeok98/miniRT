/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:03:28 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 19:01:33 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

void	ray_at(double *dest, t_ray *ray, double t);
void	set_face_normal(t_ray *r, t_hit_record *rec);
t_bool	hit_cylinder_side(t_ray *ray, t_obj *obj, t_hit_record *rec);
void	obj_version(t_obj *obj, t_hit_record *rec, int flag);

//root[0] is denominator
//root[1] is numerator
//root[2] is root
static t_bool	hit_cylinder_cap(t_ray *ray,
	t_obj *obj, t_hit_record *rec, double *dir)
{
	double		temp[3];
	double		center[3];
	double		root[3];
	double		intersection[3];

	root[0] = vec_dot(ray->dir, dir);
	if (fabs(root[0]) < EPSILON)
		return (false);
	point_at(center, obj->position, dir, obj->cy_h / 2);
	vec_minus2(temp, center, ray->start);
	root[1] = vec_dot(temp, dir);
	root[2] = root[1] / root[0];
	if (root[2] < rec->t_min || rec->t_max < root[2])
		return (false);
	point_at(intersection, ray->start, ray->dir, root[2]);
	vec_minus2(temp, intersection, center);
	if (vec_len2(temp) > pow(obj->r / 2, 2))
		return (false);
	rec->t = root[2];
	rec->t_max = root[2];
	vec_copy(rec->pos, intersection);
	vec_copy(rec->n_v, dir);
	set_face_normal(ray, rec);
	obj_version(obj, rec, 0);
	return (true);
}

// 
t_bool	hit_cylinder(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	t_bool	side;
	t_bool	cap[2];
	double	cap_dir[3];

	vec_copy(cap_dir, obj->n_v);
	side = hit_cylinder_side(ray, obj, rec);
	cap[0] = hit_cylinder_cap(ray, obj, rec, cap_dir);
	vec_mult(cap_dir, -1);
	cap[1] = hit_cylinder_cap(ray, obj, rec, cap_dir);
	return (side || cap[0] || cap[1]);
}
