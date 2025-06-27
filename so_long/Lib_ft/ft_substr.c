/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:19:23 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 14:45:28 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	str = (char *)malloc(((len + 1) * sizeof(char)));
	if (str != NULL)
	{
		ft_strlcpy(str, &s[start], len + 1);
	}
	return (str);
}
/*int	main ()
{
	char source[] = "Lindo bom dia feio";
	char *ok = ft_substr(source, 0, 5);
	printf("%s",ok );
	free(ok);
	return 0;
}*/
