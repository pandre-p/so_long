/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:56:33 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 10:59:18 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str_dest;
	char	*str_src;

	str_dest = (char *)dest;
	str_src = (char *)src;
	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dest);
}
/*int main()
{
    char str1[] = "Geeks";
    char str2[] = "Quiz";

    puts("str1 before memcpy ");
    puts(str1);

    ft_memcpy(str1, str2, sizeof(str2));

    puts("\nstr1 after memcpy ");
    puts(str1);

    return 0;
}*/
