/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:27:20 by klha              #+#    #+#             */
/*   Updated: 2024/04/05 19:18:23 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/screen_bonus.h"
#include "../Include/cal_vec_bonus.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

void	rotation(int k, t_mlx *mlx);
int		switch_target(int k, t_mlx *mlx);
void	draw_screen(t_mlx *mlx);
void	report_surface_status(t_mlx *mlx);

static void	switch_surface(int k, t_mlx *mlx)
{
	int	unit;

	if (mlx->target != 2)
		return ;
	unit = 1;
	if (k == DOWN)
		unit = -1;
	mlx->curr->flag += unit;
	if (mlx->curr->flag == -1)
		mlx->curr->flag = 2;
	else if (mlx->curr->flag == 3)
		mlx->curr->flag = 0;
	report_surface_status(mlx);
}

static void	move(int k, t_mlx *mlx)
{
	double	dir[3];

	if (k == W || k == S)
		vec_copy(dir, mlx->in->c->n_v);
	else if (k == D || k == A)
		vec_copy(dir, mlx->in->c->right_v);
	else if (k == E || k == Q)
		vec_copy(dir, mlx->in->c->up_v);
	if (k == S || k == A || k == E)
		vec_mult(dir, -1);
	vec_unit(dir);
	if (mlx->target == 0)
		point_at(mlx->in->c->position, mlx->in->c->position, dir, 1);
	else if (mlx->target == 1)
		point_at(mlx->light->position, mlx->light->position, dir, 1);
	else if (mlx->target == 2)
		point_at(mlx->curr->position, mlx->curr->position, dir, 1);
}

static void	push_esc(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	exit_bt(void)
{
	exit(0);
}

int	key_hook(int k, t_mlx *mlx)
{
	if (k == ESC)
		push_esc(mlx);
	else if (k == W || k == A || k == S || k == D || k == Q || k == E)
		move(k, mlx);
	else if (k == J || k == K || k == L || k == U || k == I || k == O)
		rotation(k, mlx);
	else if (k == LEFT || k == RIGHT || k == SPACE)
		return (switch_target(k, mlx));
	else if (k == UP || k == DOWN)
		switch_surface(k, mlx);
	else
		return (0);
	draw_screen(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
