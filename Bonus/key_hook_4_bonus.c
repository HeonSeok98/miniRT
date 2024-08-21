/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_4_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:37:48 by klha              #+#    #+#             */
/*   Updated: 2024/04/05 19:51:11 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/screen_bonus.h"
#include "../mlx/mlx.h"
#include "../Include/cal_vec_bonus.h"
#include <stdio.h>

void	report_surface_status(t_mlx *mlx)
{
	printf("target");
	if (mlx->curr->type == pl)
		printf(" plane");
	else if (mlx->curr->type == sp)
		printf(" sphere");
	else if (mlx->curr->type == cy)
		printf(" cylinder");
	else if (mlx->curr->type == cn)
		printf(" cone");
	printf("'s surface is ");
	if (mlx->curr->flag == 0)
		printf("default\n");
	else if (mlx->curr->flag == 1)
		printf("bumped\n");
	else if (mlx->curr->flag == 2)
		printf("checker board\n");
}

void	check_status(t_mlx *mlx)
{
	if (mlx->target == 0)
		printf("Control the camera\n");
	else if (mlx->target == 1)
		printf("Control the light\n");
	else if (mlx->target == 2)
	{
		if (mlx->curr->type == pl)
			printf("Control plane\n");
		else if (mlx->curr->type == sp)
			printf("Control sphere\n");
		else if (mlx->curr->type == cy)
			printf("Control cylinder\n");
		else if (mlx->curr->type == cn)
			printf("Control cone\n");
	}
	else
		common_error("Error\nTarget must be light, camera, object!\n");
}
