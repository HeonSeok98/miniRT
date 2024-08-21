/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_control_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:00 by klha              #+#    #+#             */
/*   Updated: 2024/04/08 16:49:24 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info_bonus.h"
#include <stdlib.h>

void	*malloc_guard(void *ptr);

t_obj	*get_last_obj(t_info *in)
{
	t_obj	*temp;
	t_obj	*new;

	temp = in->obj;
	new = (t_obj *)malloc_guard(malloc(sizeof(t_obj)));
	new->prev = 0;
	new->next = 0;
	new->flag = 0;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
		in->obj = new;
	return (new);
}

t_l	*find_last_light(t_info *in)
{
	t_l	*temp;
	t_l	*last;

	temp = in->l;
	while (temp)
	{
		last = temp;
		temp = temp->next;
	}
	return (last);
}

t_obj	*find_last_obj(t_info *in)
{
	t_obj	*temp;
	t_obj	*last;

	temp = in->obj;
	while (temp)
	{
		last = temp;
		temp = temp->next;
	}
	return (last);
}
