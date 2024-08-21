/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:41:00 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 19:06:06 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_BONUS_H
# define SCREEN_BONUS_H

# define ESC 53
# define SPACE 49
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define RR 15
# define J 38
# define K 40
# define L 37
# define I 34
# define U 32
# define O 31
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# include "info_bonus.h"

//infomation for mlx
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*color;
	int		width;
	int		height;
	int		b_p_p;
	int		s_l;
	int		endian;
	int		target;
	t_info	*in;
	t_l		*light;
	t_obj	*curr;
}	t_mlx;

#endif