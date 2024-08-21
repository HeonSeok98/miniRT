/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_control_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:49:11 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 19:01:33 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

//this ft set the dest arry where ray arrived by t
//dest : it should be double 3 arry 
void	ray_at(double *dest, t_ray *ray, double t)
{
	int	i;

	i = -1;
	while (++i < 3)
		dest[i] = ray->start[i] + ray->dir[i] * t;
}

// t_ray	ray(double *origin, double *dir)
// {
// 	t_ray	ray;

// 	ray.dir = dir;
// 	ray.start = origin;
// 	return (ray);
// }

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vec_dot(r->dir, rec->n_v) < 0;
	if (!(rec->front_face))
		vec_mult(rec->n_v, -1);
}
