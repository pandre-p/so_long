/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:30:02 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 14:41:51 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_check_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	st;
	char	*pd;

	if (!s1 || !set)
		return (NULL);
	st = 0;
	while (s1[st] && ft_check_char(s1[st], set))
		st++;
	end = ft_strlen(s1);
	while (end > st && ft_check_char(s1[end - 1], set))
		end--;
	pd = (char *)malloc((end - st + 1) * sizeof (char));
	if (!pd)
		return (NULL);
	ft_strlcpy(pd, s1 + st, end - st + 1);
	return (pd);
}
/*int	main()
{
	char	source1[] = "lorem ipsum dolor sit amet";
	char	set[] = "te";

	printf("%s", ft_strtrim(source1, set));
	return(0);

}*/
