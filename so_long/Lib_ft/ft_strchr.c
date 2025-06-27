/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:57:51 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 11:37:49 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
	{
		return ((char *)&s[i]);
	}
	return (0);
}
/*int main (void)
{
	const char	s[] = "just.a.way";
	const char	c = 'u';
	char	*ret;
	ret = ft_strchr(s, c);

	printf("%s\n", ret);

	return (0);
}*/
