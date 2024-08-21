/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_vec1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:05:06 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 18:59:29 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

//point is destination
//origin is start point
//dir is direction
//t is how many far from origin.
void	point_at(double *point, double *origin, double *dir, double t)
{
	point[X] = origin[X] + dir[X] * t;
	point[Y] = origin[Y] + dir[Y] * t;
	point[Z] = origin[Z] + dir[Z] * t;
}

void	vec_set(double *vec, double x, double y, double z)
{
	vec[X] = x;
	vec[Y] = y;
	vec[Z] = z;
}

//copy double arr vec2 to vec1
void	vec_copy(double *vec1, double *vec2)
{
	vec1[X] = vec2[X];
	vec1[Y] = vec2[Y];
	vec1[Z] = vec2[Z];
}

//get vetor's square of size 
double	vec_len2(double *vec)
{
	return (vec[X] * vec[X] + vec[Y] * vec[Y] + vec[Z] * vec[Z]);
}

//get vector's size
double	vec_len(double *vec)
{
	return (sqrt(vec_len2(vec)));
}
