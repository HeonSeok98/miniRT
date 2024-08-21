/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:27:20 by klha              #+#    #+#             */
/*   Updated: 2024/04/03 17:18:44 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/screen.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int		exit_bt(void);
void	push_esc(t_mlx *mlx);
void	rotation(int k, t_mlx *mlx);
void	move(int k, t_mlx *mlx);
void	draw_screen(t_mlx *mlx);
void	check_status(t_mlx *mlx);

static void	set_camera_prev(t_mlx *mlx)
{
	if (mlx->in->flag_any)
	{
		mlx->target = 1;
		mlx->light = mlx->in->l;
	}
	else
	{
		mlx->target = 2;
		mlx->curr = mlx->in->obj;
		if (mlx->curr->prev)
			mlx->curr = mlx->curr->prev;
	}
}

static void	set_previous(t_mlx *mlx)
{
	if (mlx->target == 0)
		set_camera_prev(mlx);
	else if (mlx->target == 1)
		mlx->target = 0;
	else if (mlx->target == 2)
	{
		if (!mlx->curr->prev)
			mlx->target = 1;
		else if (mlx->curr == mlx->in->obj)
			mlx->target = 1;
		else
			mlx->curr = mlx->curr->prev;
	}
	check_status(mlx);
}

static void	setting_obj(t_mlx *mlx)
{
	if (mlx->curr->next)
		mlx->curr = mlx->curr->next;
	else
		mlx->target = 0;
}

static void	set_next(t_mlx *mlx)
{
	if (mlx->target == 0)
	{
		mlx->target = 1;
		mlx->light = mlx->in->l;
	}
	else if (mlx->target == 1)
	{
		if (mlx->light->next)
			mlx->light = mlx->light->next;
		else
		{
			if (mlx->in->obj)
			{
				mlx->target = 2;
				mlx->curr = mlx->in->obj;
			}
			else
				mlx->target = 0;
		}
	}
	else if (mlx->target == 2)
		setting_obj(mlx);
	check_status(mlx);
}

int	key_hook(int k, t_mlx *mlx)
{
	if (k == ESC)
		push_esc(mlx);
	else if (k == W || k == A || k == S || k == D || k == Q || k == E)
		move(k, mlx);
	else if (k == J || k == K || k == L || k == U || k == I || k == O)
		rotation(k, mlx);
	else if (k == SPACE)
		mlx->target = 0;
	else if (k == LEFT)
	{
		set_previous(mlx);
		return (0);
	}
	else if (k == RIGHT)
	{
		set_next(mlx);
		return (0);
	}
	else
		return (0);
	draw_screen(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
