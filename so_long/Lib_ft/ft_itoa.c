/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:34:37 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 10:48:25 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len] = '0' + (number % 10);
		number = number / 10;
		len--;
	}
	return (s);
}

long int	ft_count(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	len;
	int		number;

	len = ft_count(n);
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = ft_char(s, number, len);
	return (s);
}
/*int main ()
{
	printf("%s", ft_itoa(-21331));
}*/
