/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_vec4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:19:21 by klha              #+#    #+#             */
/*   Updated: 2024/04/01 20:45:05 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cal_vec.h"

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
