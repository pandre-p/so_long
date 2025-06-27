/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:51 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/22 11:52:01 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		n = ft_lstnew((*f)(lst->content));
		if (!n)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, n);
		lst = lst->next;
	}
	return (new);
}
/*
static void free_num(void *num_ptr) {
    free(num_ptr);
}

static void *add_one(void *num_ptr) {
    int *num = (int *)num_ptr;
    int *result = malloc(sizeof(int));
    if (result)
    {
	    *result = (*num) + 1;
	    return result;
    }
    else
    {
	    fprintf(stderr, "Erro de alocação de memória\n");
	    exit(EXIT_FAILURE);
    }
}
int main() 
{
	t_list *lst = ft_lstnew(ft_calloc(1, sizeof(int)));
	*((int *)lst->content) = 1;
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(int))));
	*((int *)lst->next->content) = 2;
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(int))));
	*((int *)lst->next->next->content) = 3;
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(int))));
	*((int *)lst->next->next->next->content) = 4;
	ft_lstadd_back(&lst, ft_lstnew(ft_calloc(1, sizeof(int))));
	*((int *)lst->next->next->next->next->content) = 5;
	
	t_list *new_lst = ft_lstmap(lst, &add_one, &free_num);
	
	printf("Lista original: ");
	t_list *temp = lst;
	while (temp) 
	{
		printf("%d ", *((int *)temp->content));
		temp = temp->next;
	}
	printf("\n");
	
	printf("Nova lista (cada elemento incrementado em 1): ");
	temp = new_lst;
	while (temp) 
	{
		printf("%d ", *((int *)temp->content));
		temp = temp->next;
	}
	printf("\n");
	
	ft_lstclear(&lst, &free_num);
	ft_lstclear(&new_lst, &free_num);
	
	return 0;
}*/
