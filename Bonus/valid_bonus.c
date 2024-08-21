/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:10:10 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 13:57:18 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include "../Include/cal_vec_bonus.h"
#include <fcntl.h>
#include <stdlib.h>

void	common_error(char *str);
void	start_parsing(t_info *in, char *str, int fd);
void	*malloc_guard(void *ptr);

void	decimal_cnt(int	*cnt)
{
	(*cnt)++;
	if (*cnt > 6)
		common_error("Error\nToo many decimal places!\n");
}

void	check_double(double n)
{
	if (n > 1000.0 - EPSILON)
		common_error("Error\nImproper number!\n");
}

void	set_default(t_info *in)
{
	in->flag_a = 1;
	in->flag_c = 1;
	in->flag_l = 1;
	in->flag_any = 1;
	in->a = (t_a *)malloc_guard(malloc(sizeof(t_a)));
	in->c = (t_c *)malloc_guard(malloc(sizeof(t_c)));
	in->l = (t_l *)malloc_guard(malloc(sizeof(t_l)));
	in->l->next = 0;
	in->l->prev = 0;
	in->obj = 0;
}

void	valid_test(t_info *in, char *file)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (len < 4)
		common_error("file name is wrong! We need only \"*.rt\"!\n");
	if (ft_strcmp(".rt", file + len - 3))
		common_error("file name is wrong! We need only \"*.rt\"!\n");
	set_default(in);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		common_error("open failed!\n");
	start_parsing(in, file, fd);
}

void	check_dir(double *dir)
{
	if (dir[X] == 0.0 && dir[Y] == 0.0 && dir[Z] == 0.0)
		common_error("Error\nDirection or normal vector is 0-vector!\n");
	vec_unit(dir);
}
