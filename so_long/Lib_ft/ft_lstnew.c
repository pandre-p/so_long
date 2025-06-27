/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:42:56 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/15 08:44:14 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_n;

	new_n = (t_list *)malloc(sizeof(t_list));
	if (new_n == NULL)
		return (NULL);
	new_n->content = content;
	new_n->next = NULL;
	return (new_n);
}
/*int main(int ac, char **av)
{
	t_list *ok = ft_lstnew(av[1]);
	ft_putstr_fd(ok->content, 1);
}*/
