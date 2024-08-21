/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:32:55 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 17:17:25 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/screen_bonus.h"
#include "../mlx/mlx.h"
#include <stdio.h>

void	check_status(t_mlx *mlx);
t_l		*find_last_light(t_info *in);

static void	set_camera_prev(t_mlx *mlx)
{
	if (mlx->in->flag_any)
	{
		mlx->target = 1;
		mlx->light = find_last_light(mlx->in);
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
	{
		if (mlx->light->prev)
			mlx->light = mlx->light->prev;
		else
			mlx->target = 0;
	}
	else if (mlx->target == 2)
	{
		if (!mlx->curr->prev)
		{
			mlx->target = 1;
			mlx->light = find_last_light(mlx->in);
		}
		else if (mlx->curr == mlx->in->obj)
			mlx->target = 1;
		else
			mlx->curr = mlx->curr->prev;
	}
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
}

int	switch_target(int k, t_mlx *mlx)
{
	if (k == LEFT)
		set_previous(mlx);
	else if (k == RIGHT)
		set_next(mlx);
	else if (k == SPACE)
		mlx->target = 0;
	check_status(mlx);
	return (0);
}
