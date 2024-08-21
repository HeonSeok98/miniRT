/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:56:58 by klha              #+#    #+#             */
/*   Updated: 2024/04/04 17:07:19 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info.h"
#include <stdio.h>

void	valid_test(t_info *in, char *file);
void	init_mlx(t_info	*in);

void	free_for_all(t_info *in)
{
	t_l		*light;
	t_l		*tp;
	t_obj	*obj;
	t_obj	*temp;

	obj = in->obj;
	light = in->l;
	free(in->a);
	free(in->c);
	while (light)
	{
		tp = light->next;
		free(light);
		light = tp->next;
	}
	while (obj)
	{
		temp = obj->next;
		free(obj);
		obj = temp;
	}
}

// void	check_leak(void)
// {
// 	system("leaks -q miniRT");
// }
// 	atexit(check_leak);

int	main(int ac, char **av)
{
	t_info	in;

	if (ac != 2)
	{
		ft_printf_fd(2, "We need only \"*.rt\" file for arg!");
		return (1);
	}
	valid_test(&in, av[1]);
	init_mlx(&in);
	free_for_all(&in);
	return (0);
}
