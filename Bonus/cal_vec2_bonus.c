/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_vec2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:35:17 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 18:59:34 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"

void	vec_plus(double *vec1, double *vec2)
{
	vec1[X] += vec2[X];
	vec1[Y] += vec2[Y];
	vec1[Z] += vec2[Z];
}

void	vec_minus(double *vec1, double *vec2)
{
	vec1[X] -= vec2[X];
	vec1[Y] -= vec2[Y];
	vec1[Z] -= vec2[Z];
}

//vector * scalar value
void	vec_mult(double *vec, double t)
{
	vec[X] *= t;
	vec[Y] *= t;
	vec[Z] *= t;
}

//multipication each element
// (x1 * x2, y1 * y2, z1 * z2)
void	vec_mult2(double *vec1, double *vec2)
{
	vec1[X] *= vec2[X];
	vec1[Y] *= vec2[Y];
	vec1[Z] *= vec2[Z];
}

//vector divided by scalar
void	vec_divide(double *vec, double t)
{
	if (t == 0)
		common_error("0 Division Error\n");
	vec[X] /= t;
	vec[Y] /= t;
	vec[Z] /= t;
}
