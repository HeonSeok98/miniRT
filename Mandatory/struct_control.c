/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:09:00 by klha              #+#    #+#             */
/*   Updated: 2024/04/03 13:29:30 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/info.h"
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
