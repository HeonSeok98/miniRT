/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:35:52 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 19:01:33 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

t_bool	hit_object(t_ray *ray, t_obj *obj, t_hit_record *rec);

//set default hit record structure
void	hit_record_init(t_hit_record *rec)
{
	rec->t_min = EPSILON;
	rec->t_max = INFINITY;
	rec->front_face = false;
}

//in judge ray hit some object whether or not
t_bool	hit(t_info *in, t_ray *ray, t_hit_record *rec)
{
	t_bool			is_hit;
	t_obj			*now;

	is_hit = false;
	hit_record_init(rec);
	now = in->obj;
	while (now)
	{
		if (hit_object(ray, now, rec))
			is_hit = true;
		now = now->next;
	}
	return (is_hit);
}
