/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_side_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:33:37 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 19:01:33 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

void	ray_at(double *dest, t_ray *ray, double t);
void	set_face_normal(t_ray *r, t_hit_record *rec);
void	obj_version(t_obj *obj, t_hit_record *rec, int flag);

t_bool	check_height(t_ray *ray, t_obj *obj, t_hit_record *rec, double root)
{
	double	point[3];
	double	height;
	double	position[3];
	double	center[3];

	point_at(point, ray->start, ray->dir, root);
	vec_minus(point, obj->position);
	height = fabs(vec_dot(point, obj->n_v));
	if (height > obj->cy_h / 2)
		return (false);
	rec->t = root;
	rec->t_max = root;
	ray_at(rec->pos, ray, rec->t);
	vec_minus2(point, rec->pos, obj->position);
	point_at(center, obj->position, obj->n_v, vec_dot(point, obj->n_v));
	vec_minus2(position, rec->pos, center);
	vec_unit(position);
	vec_copy(rec->n_v, position);
	set_face_normal(ray, rec);
	obj_version(obj, rec, 1);
	return (true);
}

static double	get_c(t_obj *obj, double *q)
{
	return (vec_dot(q, q) - \
		pow(vec_dot(q, obj->n_v), 2) - pow(obj->r / 2, 2));
}

static double	get_b(t_ray *ray, t_obj *obj, double *q)
{
	return (vec_dot(ray->dir, q) - \
		(vec_dot(ray->dir, obj->n_v) * vec_dot(q, obj->n_v)));
}

/*
P = O + tD
O = ray origin
D = ray direction vector
t = root

A = center of cylinder
d = cylinder direction vector
r = cylinder radius

let say O - A = Q...

cylinder side equation is 
(D * D - (D * d)^2)t^2 + 
2((D * Q) - (D * d)(Q * d))t + 
Q * Q - (Q * d)^2 - r^2 = 0
*/
t_bool	hit_cylinder_side(t_ray *ray, t_obj *obj, t_hit_record *rec)
{
	double	coeff[3];
	double	q[3];
	double	discriminant;
	double	root;
	double	sqrtd;

	vec_minus2(q, ray->start, obj->position);
	coeff[0] = vec_dot(ray->dir, ray->dir) - \
		pow(vec_dot(ray->dir, obj->n_v), 2);
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
	return (check_height(ray, obj, rec, root));
}
