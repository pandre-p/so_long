/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:57:11 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 12:52:03 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i] != '\0')
	{
		i++;
	}
	while ((i + 1) < size && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (i != size)
	{
		dst[i] = '\0';
	}
	return ((i - j) + ft_strlen(src));
}
/*int main(void)
{
	char s1[] = "";
	char s2[] = "adadada";
	size_t	ret;
	size_t	res;

	res = strlcat(s1, s2, 6);
	ret = ft_strlcat(s1, s2, 6);

	printf("%zu orig\n", res);
	printf("%zu meu\n", ret);
	return(0);
}*/
