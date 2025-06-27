/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:55:43 by ppassos           #+#    #+#             */
/*   Updated: 2024/04/21 12:33:46 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = (char) c;
		i++;
	}
	return (s);
}
/*int main()
{
    char str[50] = "ola batata tudo bem?";
    printf("\nBefore memset(): %s\n", str);

    ft_memset(str + 4, '.', 7*sizeof(char));

    printf("After memset():  %s", str);
    return 0;
}*/
