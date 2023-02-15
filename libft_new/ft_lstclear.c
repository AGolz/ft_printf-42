/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:44:15 by emaksimo          #+#    #+#             */
/*   Updated: 2023/01/18 01:44:28 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;

	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		elem = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = elem;
	}
}
