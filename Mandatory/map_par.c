/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_par.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:49:50 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 18:06:31 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../Include/info.h"

void	common_error(char *str);
void	throw_w_sp(char **line, int flag);
void	set_a(char *line, t_info *in);
void	set_c(char *line, t_info *in);
void	set_l(char *line, t_info *in);
void	set_sp(char *line, t_obj *sph);
void	set_pl(char *line, t_obj *pla);
void	set_cy(char *line, t_obj *cyl);
t_obj	*get_last_obj(t_info *in);
t_obj	*find_last_obj(t_info *in);

// this ft categorizing component
// return 0 = success
// return 1 = fail. program terminated
static void	set_obj_default(char *line, t_info *in, t_compo type)
{
	t_obj	*obj;

	throw_w_sp(&line, 0);
	if (!*line)
		common_error("Error\nWe need object infomation!\n");
	if (in->flag_any)
		in->flag_any = 0;
	obj = get_last_obj(in);
	if (type == sp)
		set_sp(line, obj);
	else if (type == pl)
		set_pl(line, obj);
	else if (type == cy)
		set_cy(line, obj);
}

static void	categorize(t_info *in, char *temp, char *str, char *line)
{
	if (*temp && *temp == 'A')
		set_a(++temp, in);
	else if (*temp && *temp == 'C')
		set_c(++temp, in);
	else if (*temp && *temp == 'L')
		set_l(++temp, in);
	else if (*temp && temp[0] == 's' && *(temp + 1) && temp[1] == 'p')
		set_obj_default(temp + 2, in, sp);
	else if (*temp && temp[0] == 'p' && *(temp + 1) && temp[1] == 'l')
		set_obj_default(temp + 2, in, pl);
	else if (*temp && temp[0] == 'c' && *(temp + 1) && temp[1] == 'y')
		set_obj_default(temp + 2, in, cy);
	else
	{
		ft_printf_fd(2, "Error\nBad line in %s!\n", str);
		ft_printf_fd(2, "please checkout : %s", line);
		common_error("\n");
	}
}

static int	check_skip(char *str)
{
	if (*str == '\n' || *str == '#')
		return (1);
	else if (*str == '/')
	{
		str++;
		if (*str == '/')
			return (1);
	}
	return (0);
}

static void	last_check(t_info *in, int fd)
{
	if (in->flag_a || in->flag_c || in->flag_l)
		common_error("Error\n A or C or L is not enough!\n");
	if (in->c->position[X] > 100 || in->c->position[X] < -100 || \
		in->c->position[Y] > 100 || in->c->position[Y] < -100 || \
		in->c->position[Z] > 100 || in->c->position[Z] < -100)
	{
		ft_printf_fd(2, "Error\nCamera position");
		common_error(" coordinate must be between -100 and 100!\n");
	}
	if (!in->flag_any)
	{
		if (in->obj->next)
			in->obj->prev = find_last_obj(in);
	}
	close(fd);
}

void	start_parsing(t_info *in, char *str, int fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	while (line)
	{
		temp = line;
		throw_w_sp(&temp, 1);
		if (!*temp)
		{
			char_dangling(&line);
			break ;
		}
		else if (check_skip(temp))
		{
			char_dangling(&line);
			line = get_next_line(fd);
			continue ;
		}
		categorize(in, temp, str, line);
		char_dangling(&line);
		line = get_next_line(fd);
	}
	last_check(in, fd);
}
