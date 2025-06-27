/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:28:44 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 12:49:06 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	i;
	char			*pd;

	c = 0;
	i = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	pd = malloc((a + b + 1) * sizeof(char));
	if (pd == NULL)
		return (NULL);
	while (i < a)
	{
		pd[i] = s1[i];
		i++;
	}
	while (i < (b + a))
		pd[i++] = s2[c++];
	pd[i] = '\0';
	return (pd);
}
/*int	main()
{
	char	source1[] = "Finalmente";
	char	source2[] = ",afinal era facil";

	printf("%s", ft_strjoin(source1, source2));
	return(0);
}*/
