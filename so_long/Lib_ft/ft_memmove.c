/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:56:45 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 11:32:58 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*okfuction(size_t n, char *d, char *s)
{
	while (n > 0)
	{
		*d-- = *s--;
		n--;
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = dest;
	s = (char *)src;
	if (!src && !dest)
		return (0);
	if (d <= s || d >= (s + n))
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		d = d + n - 1;
		s = s + n - 1;
		okfuction(n, d, s);
	}
	return (dest);
}
/*int main() 
{
    char src[] = "Hello, World!";
    char dest[50];

    ft_memmove(dest, src, strlen(src) + 1);

    printf("%s \n", dest);

    char overlap[] = "1234567890";
    printf("\"%s\"\n", overlap);
    ft_memmove(overlap + 4, overlap, 6);
    printf("\"%s\"\n", overlap);
    return (0);
}*/
