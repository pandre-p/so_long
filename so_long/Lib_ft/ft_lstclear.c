/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:52:35 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/15 13:28:36 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ant;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		ant = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = ant;
	}
}
