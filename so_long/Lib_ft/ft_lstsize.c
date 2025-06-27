/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:45:54 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/15 09:29:05 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*int main(int ac,char **av)
 {
	 t_list *o1 = ft_lstnew(av[1]);
	 t_list *o2 = ft_lstnew(av[2]);
	 t_list *o3 = ft_lstnew(av[3]);
	 t_list *o4 = ft_lstnew(av[4]);
	 
	 ft_lstadd_front(&o1,o2);
	 ft_lstadd_front(&o1,o3);
	 ft_lstadd_front(&o1,o4);
	 ft_putnbr_fd(ft_lstsize((o1)),1);
	 while(o1 != NULL)
	 {
		 ft_putchar_fd('\n',1);
		 ft_putstr_fd(o1->content,1);
		 o1 = o1-> next;
	 }
 }*/
