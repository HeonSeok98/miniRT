/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:22:26 by klha              #+#    #+#             */
/*   Updated: 2023/10/11 18:22:46 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_one;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_one = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_one;
	}
}
