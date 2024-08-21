/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object._bonusc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:06:37 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 20:44:00 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

void	ray_at(double *dest, t_ray *ray, double t);
void	set_face_normal(t_ray *r, t_hit_record *rec);
t_bool	hit_cylinder(t_ray *ray, t_obj *obj, t_hit_record *rec);
t_bool	hit_cone(t_ray *ray, t_obj *obj, t_hit_record *rec);
void	obj_version(t_obj *obj, t_hit_record *rec, int flag);

//alpha version of hit_plane
//it could be editted...almostly...
//intersection point is (ray->start + ray->dir * x)
//so we should get x
//x = ((obj->pos) - (ray->start)) * obj->n_v / (ray->dir * obj->n_v)

t_bool	hit_plane(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	double	denominator;
	double	root;
	double	numerator;
	double	temp[3];

	denominator = vec_dot(ray->dir, obj->n_v);
	if (fabs(denominator) < EPSILON)
		return (false);
	vec_copy(temp, obj->position);
	vec_minus(temp, ray->start);
	numerator = vec_dot(temp, obj->n_v);
	root = numerator / denominator;
	if (root < rec->t_min || rec->t_max < root)
		return (false);
	rec->t_max = root;
	rec->t = root;
	ray_at(rec->pos, ray, root);
	vec_copy(rec->n_v, obj->n_v);
	set_face_normal(ray, rec);
	obj_version(obj, rec, 0);
	return (true);
}

//co is coefficient of equation
t_bool	hit_spere(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	double	co[3];
	double	root;
	double	oc[3];

	vec_minus2(oc, ray->start, obj->position);
	co[0] = vec_dot(ray->dir, ray->dir);
	co[1] = vec_dot(ray->dir, oc);
	co[2] = vec_dot(oc, oc) - (obj->r / 2) * (obj->r / 2);
	if ((co[1] * co[1]) - (co[0] * co[2]) < 0)
		return (false);
	root = (co[1] * (-1) - sqrt((co[1] * co[1]) - (co[0] * co[2]))) / co[0];
	if (root < rec->t_min || rec->t_max < root)
	{
		root = (co[1] * (-1) + sqrt((co[1] * co[1]) - (co[0] * co[2]))) / co[0];
		if (root < rec->t_min || rec->t_max < root)
			return (false);
	}
	rec->t = root;
	rec->t_max = root;
	ray_at(rec->pos, ray, rec->t);
	vec_minus2(rec->n_v, rec->pos, obj->position);
	vec_unit(rec->n_v);
	set_face_normal(ray, rec);
	obj_version(obj, rec, 0);
	return (true);
}

t_bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	if (obj->type == sp)
	{
		if (hit_spere(ray, obj, rec))
			return (true);
	}
	else if (obj->type == pl)
	{
		if (hit_plane(ray, obj, rec))
			return (true);
	}
	else if (obj->type == cy)
		return (hit_cylinder(ray, obj, rec));
	else if (obj->type == cn)
		return (hit_cone(ray, obj, rec));
	return (false);
}
