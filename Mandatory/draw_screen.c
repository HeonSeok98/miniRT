/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:54:00 by heolee            #+#    #+#             */
/*   Updated: 2024/04/04 17:01:28 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info.h"
#include "../Include/cal_vec.h"
#include "../Include/screen.h"
#include "../mlx/mlx.h"

void	set_point(t_mlx *mlx, int x, int y, int z);
int		get_color(t_info *in, t_ray *ray);

static void	cam_set_first(t_mlx *mlx)
{
	t_c		*cam;
	double	tmp[3];
	double	vec_y[3];
	double	vec_z[3];

	cam = mlx->in->c;
	vec_set(vec_y, 0, 1, 0);
	vec_set(vec_z, 0, 0, 1);
	vec_cross(tmp, cam->n_v, vec_y);
	if (!vec_len(tmp))
		vec_cross(tmp, cam->n_v, vec_z);
	vec_unit(tmp);
	vec_mult(tmp, mlx->width);
	vec_copy(cam->right_v, tmp);
	vec_cross(tmp, cam->right_v, cam->n_v);
	vec_unit(tmp);
	vec_mult(tmp, mlx->height);
	vec_copy(cam->up_v, tmp);
}

static void	cam_init(t_mlx *mlx)
{
	t_c		*cam;
	double	tmp[3];

	cam_set_first(mlx);
	cam = mlx->in->c;
	cam->focal_len = mlx->width / 2 / tan(cam->fov * M_PI / 360);
	vec_copy(cam->left_bottom, cam->n_v);
	vec_unit(cam->left_bottom);
	vec_mult(cam->left_bottom, cam->focal_len);
	vec_plus(cam->left_bottom, cam->position);
	vec_copy(tmp, cam->right_v);
	vec_mult(tmp, 0.5);
	vec_minus(cam->left_bottom, tmp);
	vec_copy(tmp, cam->up_v);
	vec_mult(tmp, 0.5);
	vec_minus(cam->left_bottom, tmp);
}

static void	ray_init(t_ray *ray, t_c *cam, double u, double v)
{
	double	tmp1[3];
	double	tmp2[3];

	vec_copy(ray->start, cam->position);
	vec_copy(tmp1, cam->left_bottom);
	vec_copy(tmp2, cam->right_v);
	vec_mult(tmp2, u);
	vec_plus(tmp1, tmp2);
	vec_copy(tmp2, cam->up_v);
	vec_mult(tmp2, v);
	vec_plus(tmp1, tmp2);
	vec_minus(tmp1, cam->position);
	vec_unit(tmp1);
	vec_copy(ray->dir, tmp1);
}

void	draw_screen(t_mlx *mlx)
{
	int		idx[2];
	double	u;
	double	v;
	t_ray	ray;
	int		color;

	if (mlx->in->c->fov == 0)
		return ;
	cam_init(mlx);
	idx[0] = 0;
	while (idx[0] < mlx->width)
	{
		idx[1] = 0;
		while (idx[1] < mlx->height)
		{
			u = (double)(idx[0]) / (mlx->width - 1);
			v = (double)(idx[1]) / (mlx->height - 1);
			ray_init(&ray, mlx->in->c, u, v);
			color = get_color(mlx->in, &ray);
			set_point(mlx, idx[0], idx[1], color);
			idx[1]++;
		}
		idx[0]++;
	}
}
