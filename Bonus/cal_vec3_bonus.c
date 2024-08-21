/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_vec3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:36:12 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 18:59:39 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

//vector's dot product
double	vec_dot(double *vec1, double *vec2)
{
	return (vec1[X] * vec2[X] + vec1[Y] * vec2[Y] + vec1[Z] * vec2[Z]);
}

//vector's cross product
void	vec_cross(double *ans, double *vec1, double *vec2)
{
	ans[X] = vec1[Y] * vec2[Z] - vec1[Z] * vec2[Y];
	ans[Y] = vec1[Z] * vec2[X] - vec1[X] * vec2[Z];
	ans[Z] = vec1[X] * vec2[Y] - vec1[Y] * vec2[X];
}

void	vec_unit(double *vec)
{
	double	len;

	len = vec_len(vec);
	if (len == 0)
		common_error("0 Division Error\n");
	vec[X] /= len;
	vec[Y] /= len;
	vec[Z] /= len;
}

//set vec1 = vec2 - vec3
void	vec_minus2(double *vec1, double *vec2, double *vec3)
{
	vec1[X] = vec2[X] - vec3[X];
	vec1[Y] = vec2[Y] - vec3[Y];
	vec1[Z] = vec2[Z] - vec3[Z];
}
