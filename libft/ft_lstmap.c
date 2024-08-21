/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:59:41 by klha              #+#    #+#             */
/*   Updated: 2023/10/11 19:00:09 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_lst;
	void	*temp;

	if (!lst || !f || !del)
		return (0);
	new_lst = 0;
	while (lst)
	{
		temp = f(lst->content);
		new_node = ft_lstnew(temp);
		if (!new_node || !temp)
		{
			ft_lstclear(&new_lst, del);
			free(temp);
			temp = 0;
			new_lst = 0;
			return (0);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	new_node = 0;
	return (new_lst);
}
