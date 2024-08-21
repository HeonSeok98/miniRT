/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:21:55 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 19:01:33 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

int		get_rgb(double rgb[3]);
int		light_merge(t_info *in, t_ray *ray, t_hit_record *rec);
t_bool	hit(t_info *in, t_ray *ray, t_hit_record *rec);

int	get_color(t_info *in, t_ray *ray)
{
	int				color;
	t_bool			is_hit;
	double			tmp[3];
	t_hit_record	rec;

	is_hit = hit(in, ray, &rec);
	if (is_hit)
	{
		color = light_merge(in, ray, &rec);
		return (color);
	}
	else
	{
		vec_copy(tmp, in->a->rgb);
		vec_mult(tmp, in->a->ratio);
		return (get_rgb(tmp));
	}
}
