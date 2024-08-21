/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:16:42 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 17:27:31 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/screen.h"
#include "../mlx/mlx.h"

int		exit_bt(void);
int		key_hook(int k, t_mlx *mlx);
void	draw_screen(t_mlx *mlx);

//set rgb for mlx color
int	get_rgb(double rgb[3])
{
	int	temp;
	int	ret;

	temp = (int)(rgb[R] * 255.999);
	temp &= 0xff;
	ret = (temp << 16);
	temp = (int)(rgb[G] * 255.999);
	temp &= 0xff;
	ret |= (temp << 8);
	temp = (int)(rgb[B] * 255.999);
	temp &= 0xff;
	ret |= temp;
	return (ret);
}

//set point of mlx window (x, y) coordinate
//and set color by z(16)
void	set_point(t_mlx *mlx, int x, int y, int z)
{
	char	*dst;

	if (x < 0 || x > mlx->width)
		return ;
	else if (y < 0 || y > mlx->height)
		return ;
	dst = mlx->color + (y * mlx->s_l + x * (mlx->b_p_p / 8));
	*(unsigned int *)dst = z;
}

void	init_mlx(t_info	*in)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.width = 800;
	mlx.height = 600;
	mlx.b_p_p = 0;
	mlx.s_l = 0;
	mlx.target = 0;
	mlx.endian = 0;
	mlx.light = in->l;
	mlx.in = in;
	mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "miniRT");
	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.color = mlx_get_data_addr(mlx.img, &mlx.b_p_p, &mlx.s_l, &mlx.endian);
	draw_screen(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_bt, 0);
	mlx_loop(mlx.mlx);
}
