/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:50:05 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 16:15:48 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_BONUS_H
# define INFO_BONUS_H

# include "../libft/libft.h"

# define X 0
# define R 0
# define Y 1
# define G 1
# define Z 2
# define B 2
# define EPSILON 1e-6

//component type list
typedef enum e_compo
{
	pl,
	sp,
	cy,
	cn
}	t_compo;

//boolian!
typedef enum e_bool
{
	false,
	true
}	t_bool;

/*
information of object
common
rgb : albedo
flag = 0 is default rgb, 1 is bump, 2 is checkerboard
next : what next is. if 0, then this is the last one.
============================
type = sp
position is center of sphere
n_v is useless
r is diameter
cy_h is useless
=============================
type = pl
position is a point in plane
n_v is normal vector
r, cy_h is useless
=============================
type = cy
position is center of cylinder
n_v is normal vector
r is diameter
cy_h is height
=============================
type = cn
position is vertex of cone
n_v is direction vector
r is pow(cos(cy_h), 2)
cy_h is semi cone angle
=============================
it will be last list if next is null
*/
typedef struct s_obj
{
	t_compo			type;
	double			position[3];
	double			n_v[3];
	double			rgb[3];
	double			r;
	double			cy_h;
	double			***bump;
	int				flag;
	struct s_obj	*next;
	struct s_obj	*prev;
}	t_obj;

//this is L
//position : location
//bright : bright ratio
//rgb : albedo
//next : this is for bonus. nothing within Mandatory though...
typedef struct s_l
{
	double		position[3];
	float		bright;
	double		rgb[3];
	struct s_l	*next;
	struct s_l	*prev;
}	t_l;

//this is C
//position : location
//n_v : direction vector
//fov : angle for fov
typedef struct s_c
{
	double	position[3];
	double	n_v[3];
	double	right_v[3];
	double	up_v[3];
	double	focal_len;
	double	left_bottom[3];
	int		fov;
}	t_c;

//this is A
//ratio : bright ratio
//rgb : albedo
typedef struct s_a
{
	float	ratio;
	double	rgb[3];
}	t_a;

/*
this is information of miniRT
flas things => 1 means no data. 0 means has a data.
a : A. ambinent.
c : C. camera
l : L. light
obj : object's list.
*/
typedef struct s_info
{
	int		flag_a;
	int		flag_c;
	int		flag_l;
	int		flag_any;
	double	***bump;
	t_a		*a;
	t_c		*c;
	t_l		*l;
	t_obj	*obj;
}	t_info;

//ray
//start = ray came from
//dir = direction vector
typedef struct s_ray
{
	double	start[3];
	double	dir[3];
}	t_ray;

//hit record where ray hit
//pos : where ray hit
//n_v : normal vector
//t : distance from cam
//t_min : minimum t. default value is 0
//t_max : maximum t. default value is infinity
typedef struct s_hit_record
{
	double	pos[3];
	double	n_v[3];
	double	t;
	double	t_min;
	double	t_max;
	double	rgb[3];
	t_bool	front_face;
}	t_hit_record;

#endif