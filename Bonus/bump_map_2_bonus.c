/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:08:37 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 17:04:02 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include <fcntl.h>
#include <unistd.h>

void	*malloc_guard(void *ptr);
void	common_error(char *str);
t_obj	*find_last_obj(t_info *in);

static void	throw_trash(int fd)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 3)
	{
		line = get_next_line(fd);
		char_dangling(&line);
	}
}

static void	set_element(double	*bump, int i, char **temp)
{
	bump[i] = (double)(ft_atoi(*temp)) / 255;
	while (ft_isdigit(**temp))
		(*temp)++;
	while (**temp == ' ')
		(*temp)++;
}

static void	build_bump(t_info *in, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	*temp;

	i = -1;
	while (++i < 60)
	{
		j = -1;
		line = get_next_line(fd);
		temp = line;
		in->bump[i] = (double **)malloc_guard(malloc(sizeof(double *) * 60));
		while (++j < 60)
		{
			in->bump[i][j] = (double *)malloc_guard(malloc(sizeof(double) * 3));
			set_element(in->bump[i][j], X, &temp);
			set_element(in->bump[i][j], Y, &temp);
			set_element(in->bump[i][j], Z, &temp);
		}
		char_dangling(&line);
	}
}

static void	update_to_obj(t_info *in)
{
	t_obj	*curr;

	curr = in->obj;
	while (curr)
	{
		curr->bump = in->bump;
		curr = curr->next;
	}
}

//make arr of bump
//we ready for (60, 60) 3 - coordinate 
//bump[y][x][coord] 
void	get_bump_info(t_info *in)
{
	int	fd;

	fd = open("./Bonus/normal_map.ppm", O_RDONLY);
	if (fd == -1)
		common_error("bump file open failed!\n");
	in->bump = (double ***)malloc_guard(malloc(sizeof(double **) * 60));
	throw_trash(fd);
	build_bump(in, fd);
	update_to_obj(in);
	close(fd);
}
