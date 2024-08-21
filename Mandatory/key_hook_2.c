/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:32:55 by klha              #+#    #+#             */
/*   Updated: 2024/04/03 17:12:46 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/screen.h"
#include "../mlx/mlx.h"

void	push_esc(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	exit_bt(void)
{
	exit(0);
}

void	set_coordinate(int target, double unit, double *arr)
{
	double	*pos;

	pos = arr;
	if (unit > 0 && pos[target] + unit > 100)
		pos[target] = 100;
	else if (unit < 0 && pos[target] + unit < -100)
		pos[target] = -100;
	else
		pos[target] += unit;
}

void	move(int k, t_mlx *mlx)
{
	int		target;
	double	u_d;

	u_d = 0.5;
	if (k == Q || k == A)
		target = X;
	else if (k == W || k == S)
		target = Y;
	else if (k == E || k == D)
		target = Z;
	if (k == S || k == A || k == D)
		u_d *= -1;
	if (mlx->target == 0)
		set_coordinate(target, u_d, &(mlx->in->c->position[0]));
	else if (mlx->target == 1)
		set_coordinate(target, u_d, &(mlx->light->position[0]));
	else if (mlx->target == 2)
		set_coordinate(target, u_d, &(mlx->curr->position[0]));
}
