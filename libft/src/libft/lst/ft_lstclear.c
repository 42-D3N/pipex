/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:26:45 by tle-pape          #+#    #+#             */
/*   Updated: 2024/10/26 10:37:28 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
/*
Check if the del function, lst and the first node exist.
If one of the three is missing, stop the function here.
Otherwize, while lst isn't empty and while a node exist, keep the next address
delete the node and add the address in next to continue in the lst until the
end.
*/
