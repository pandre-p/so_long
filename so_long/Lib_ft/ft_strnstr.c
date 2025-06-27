/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:12:12 by ppassos           #+#    #+#             */
/*   Updated: 2024/04/30 11:42:16 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	while_return(const char *big, const char *little, size_t save)
{
	size_t	id;
	size_t	set;

	id = 0;
	set = 0;
	while (id < ft_strlen(little))
	{
		if (big[save] != little[id])
		{
			set = 1;
			break ;
		}
		save++;
		id++;
	}
	return (set);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	set;
	char	*ok;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			set = while_return(big, little, i);
			if (set == 0 && len - i >= ft_strlen(little))
			{
				ok = (char *)big;
				return (&ok[i]);
			}
		}
		i++;
	}
	return (NULL);
}
/*int main ()
{
	char *result = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10);
	printf("%s", result);

	return (0);
}*/
