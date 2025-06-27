/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:37:40 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/03 04:20:23 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*st;
	unsigned int	i;

	st = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (st == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		st[i] = f(i, s[i]);
		i++;
	}
	st[i] = '\0';
	return (st);
}
