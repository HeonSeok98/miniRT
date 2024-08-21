/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_merge_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:38:16 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 19:01:33 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

int		get_rgb(double rgb[3]);
t_bool	hit(t_info *in, t_ray *ray, t_hit_record *rec);

void	diffuse_lighting(double *all_light, t_hit_record *rec, t_l *light)
{
	double	diffuse[3];
	double	ans;
	double	light_dir[3];

	vec_minus2(light_dir, light->position, rec->pos);
	vec_unit(light_dir);
	ans = fmax(vec_dot(light_dir, rec->n_v), 0.0);
	diffuse[R] = ans * light->rgb[R] * light->bright;
	diffuse[G] = ans * light->rgb[G] * light->bright;
	diffuse[B] = ans * light->rgb[B] * light->bright;
	vec_plus(all_light, diffuse);
}

void	specular_lighting(double *all_light, \
	t_hit_record *rec, t_l *light, t_ray *ray)
{
	double	specular[3];
	double	a_vec[3];
	double	ans;
	double	light_dir[3];

	vec_set(a_vec, rec->n_v[X], rec->n_v[Y], rec->n_v[Z]);
	vec_minus2(light_dir, light->position, rec->pos);
	vec_unit(light_dir);
	vec_mult(a_vec, vec_dot(light_dir, a_vec));
	vec_mult(light_dir, -1);
	vec_plus(light_dir, a_vec);
	vec_plus(light_dir, a_vec);
	vec_mult(ray->dir, -1);
	ans = pow(fmax(vec_dot(light_dir, ray->dir), 0), 64);
	specular[R] = ans * light->rgb[R] * light->bright;
	specular[G] = ans * light->rgb[G] * light->bright;
	specular[B] = ans * light->rgb[B] * light->bright;
	vec_plus(all_light, specular);
	vec_mult(ray->dir, -1);
}

t_bool	is_shadow(t_info *in, t_l *light, t_hit_record	*rec)
{
	t_hit_record	shadow_rec;
	t_ray			shadow_ray;
	t_bool			ans;

	vec_copy(shadow_ray.start, rec->pos);
	vec_minus2(shadow_ray.dir, light->position, rec->pos);
	vec_unit(shadow_ray.dir);
	ans = hit(in, &shadow_ray, &shadow_rec);
	vec_minus2(shadow_ray.dir, light->position, rec->pos);
	if (shadow_rec.t + EPSILON > vec_len(shadow_ray.dir))
		return (false);
	return (ans);
}

int	light_merge(t_info *in, t_ray *ray, t_hit_record *rec)
{
	double	all_light[3];
	t_l		*now;

	vec_set(all_light, 0, 0, 0);
	vec_plus(all_light, in->a->rgb);
	vec_mult(all_light, in->a->ratio);
	now = in->l;
	while (now)
	{
		if (!is_shadow(in, now, rec))
		{
			diffuse_lighting(all_light, rec, now);
			specular_lighting(all_light, rec, now, ray);
		}
		now = now->next;
	}
	vec_mult2(all_light, rec->rgb);
	all_light[X] = fmin(all_light[X], 1.0);
	all_light[Y] = fmin(all_light[Y], 1.0);
	all_light[Z] = fmin(all_light[Z], 1.0);
	return (get_rgb(all_light));
}
