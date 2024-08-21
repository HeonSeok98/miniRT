/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_vec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:41:43 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 18:47:51 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAL_VEC_H
# define CAL_VEC_H

# include "info.h"
# include <math.h>

double	vec_len2(double *vec);
double	vec_len(double *vec);
void	vec_plus(double *vec1, double *vec2);
void	vec_minus(double *vec1, double *vec2);
void	vec_mult(double *vec, double t);
void	vec_mult2(double *vec1, double *vec2);
void	vec_divide(double *vec, double t);
double	vec_dot(double *vec1, double *vec2);
void	vec_cross(double *ans, double *vec1, double *vec2);
void	vec_unit(double *vec);
double	*create_vec_unit(double *vec);
void	vec_set(double *vec, double x, double y, double z);
void	vec_copy(double *vec1, double *vec2);
void	vec_minus2(double *vec1, double *vec2, double *vec3);
void	point_at(double *point, double *origin, double *dir, double t);

void	*malloc_guard(void *ptr);
void	common_error(char *str);

#endif
