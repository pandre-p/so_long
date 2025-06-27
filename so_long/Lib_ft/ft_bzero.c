/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:55:56 by ppassos           #+#    #+#             */
/*   Updated: 2024/04/23 15:05:13 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}
/*int main(void)
{
    char str[50] = "stopsjfsofjsfjsofsji";
    printf("\n Before bzero(): %s\n", str);

    ft_bzero(str + 4, 8*sizeof(char));

    printf("After bzero():  %s", str);
    return 0;
}*/
