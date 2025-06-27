/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:58:02 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 12:55:31 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0' && s[i] == '\0')
	{
		return ((char *)(s));
	}
	if (s[i] == '\0')
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		i++;
	}
	while (i != -1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*int main (void)
{
	const char	s[] = "";
	const char	c = '\0';
	char	*ret;
	ret = ft_strrchr(s, c);

	printf("%s\n", ret);
	return (0);
}*/
