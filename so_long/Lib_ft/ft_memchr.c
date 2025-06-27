/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:58:52 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 10:57:04 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
	const char s[] = "just a way";
	const char c = 'a';
	char *ret;
	int a = 10;

	ret = ft_memchr(s, c, a);

	printf("%s\n", ret);

	return (0);
}*/
