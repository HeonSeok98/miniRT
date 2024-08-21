/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:21:13 by klha              #+#    #+#             */
/*   Updated: 2024/04/05 19:04:45 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

void	ray_at(double *dest, t_ray *ray, double t);
void	set_face_normal(t_ray *r, t_hit_record *rec);
void	obj_version(t_obj *obj, t_hit_record *rec, int flag);

static t_bool	setting_cone(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	double	point[3];
	double	height;
	double	position[3];
	double	center[3];

	point_at(point, ray->start, ray->dir, rec->t);
	vec_minus(point, obj->position);
	height = vec_dot(point, obj->n_v);
	rec->t_max = rec->t;
	ray_at(rec->pos, ray, rec->t);
	vec_minus2(point, rec->pos, obj->position);
	point_at(center, obj->position, obj->n_v, height);
	vec_minus2(position, rec->pos, center);
	vec_unit(position);
	vec_copy(rec->n_v, position);
	set_face_normal(ray, rec);
	obj_version(obj, rec, 0);
	return (true);
}

static double	get_c(t_obj *obj, double *q)
{
	return (vec_dot(q, q) - \
		(pow(vec_dot(q, obj->n_v), 2) / obj->r));
}

static double	get_b(t_ray *ray, t_obj *obj, double *q)
{
	return (vec_dot(ray->dir, q) - \
		(vec_dot(ray->dir, obj->n_v) * vec_dot(q, obj->n_v) / obj->r));
}

/*
P = O + tD
O = ray origin
D = ray direction vector
t = root

A = vertex of cone
B = cone direction vectpor
r = power of cos(semi cone angle)

let say O - A = Q...

cone equation is 
(D * D - ((D * B)^2 / r))t^2 + 
2((D * Q) - ((D * B)(Q * B) / r))t + 
Q * Q - ((Q * B)^2 / r) = 0
*/
t_bool	hit_cone(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	double	coeff[3];
	double	q[3];
	double	discriminant;
	double	root;
	double	sqrtd;

	vec_minus2(q, ray->start, obj->position);
	coeff[0] = vec_dot(ray->dir, ray->dir) - \
		(pow(vec_dot(ray->dir, obj->n_v), 2) / obj->r);
	coeff[1] = get_b(ray, obj, q);
	coeff[2] = get_c(obj, q);
	discriminant = (coeff[1] * coeff[1]) - (coeff[0] * coeff[2]);
	if (discriminant < 0)
		return (false);
	sqrtd = sqrt(discriminant);
	root = -1 * (coeff[1] + sqrtd) / coeff[0];
	if (root < rec->t_min || rec->t_max < root)
	{
		root = -1 * (coeff[1] - sqrtd) / coeff[0];
		if (root < rec->t_min || rec->t_max < root)
			return (false);
	}
	rec->t = root;
	return (setting_cone(ray, obj, rec));
}
