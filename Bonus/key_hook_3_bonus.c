/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:17:13 by klha              #+#    #+#             */
/*   Updated: 2024/04/05 19:58:23 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/screen_bonus.h"
#include "../mlx/mlx.h"
#include "../Include/cal_vec_bonus.h"
#include <stdio.h>

double	radian(double x);

static void	get_rotate_matrix(double rotate[3][3],
	double c, double s, int target)
{
	if (target == X)
	{
		vec_set(rotate[0], 1, 0, 0);
		vec_set(rotate[1], 0, c, -1 * s);
		vec_set(rotate[2], 0, s, c);
	}
	else if (target == Y)
	{
		vec_set(rotate[0], c, 0, s);
		vec_set(rotate[1], 0, 1, 0);
		vec_set(rotate[2], -1 * s, 0, c);
	}
	else if (target == Z)
	{
		vec_set(rotate[0], c, -1 * s, 0);
		vec_set(rotate[1], s, c, 0);
		vec_set(rotate[2], 0, 0, 1);
	}
}

static void	set_rotate(int target, int flag, double *dir)
{
	double	rotate[3][3];
	double	ret[3];
	double	c;
	double	s;

	c = cos(radian(flag));
	s = sin(radian(flag));
	get_rotate_matrix(rotate, c, s, target);
	vec_set(ret,
		vec_dot(rotate[0], dir),
		vec_dot(rotate[1], dir),
		vec_dot(rotate[2], dir));
	vec_unit(ret);
	vec_copy(dir, ret);
}

void	rotation(int k, t_mlx *mlx)
{
	int	target;
	int	flag;

	if (mlx->target == 1)
		return ;
	else if (mlx->target == 2 && mlx->curr && mlx->curr->type == sp)
		return ;
	flag = 1;
	if (k == J || k == L)
		target = Y;
	else if (k == K || k == I)
		target = X;
	else if (k == U || k == O)
		target = Z;
	if (k == L || k == I || k == U)
		flag = -1;
	if (mlx->target == 0)
		set_rotate(target, flag * 10, &(mlx->in->c->n_v[0]));
	else if (mlx->target == 2)
		set_rotate(target, flag * 30, &(mlx->curr->n_v[0]));
}
