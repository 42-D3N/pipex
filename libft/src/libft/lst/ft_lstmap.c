/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:47 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 10:47:23 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*init;
	t_list	*new;
	void	*new_content;

	if (!f || !del || !lst)
		return (NULL);
	init = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			(*del)(new_content);
			ft_lstclear(&init, del);
			return (init);
		}
		ft_lstadd_back(&init, new);
		lst = lst->next;
	}
	return (init);
}
/*
Check if 'f', 'del' and lst are not NULL. If one of them is NULL, return NULL.
While lst is not NULL
- Create a new element by applying f on the content.
-- If 'new' is empty, delete the content and clear the new lst.
- Call "ft_lstadd_back" to add at the end of the chain the node 'new'.
- Use 'lst = lst->next' to browse the chain.
Return the first node of the new chain.
*/
