/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:55:18 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/15 09:13:30 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int main(int ac, char **av)
{
	t_list *a1 = ft_lstnew(av[1]);
	t_list *a2 = ft_lstnew(av[2]);

	ft_lstadd_front(&a1, a2);
	ft_putstr_fd(a1->content, 1);
	a1 = a1->next;
	ft_putstr_fd(a1->content, 1);
}*/
