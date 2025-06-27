/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:12:39 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/13 10:54:12 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	num;

	i = 0;
	signal = 1;
	num = 0;
	while ((str && str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signal = signal * -1;
			i++;
		}
		else
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * signal);
}
/*int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("%s", "colocaste errado bro");
		return (0);
	}
	printf("%d", ft_atoi(&argv[1][0]));
	return (0);
}*/
