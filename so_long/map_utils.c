/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:35:59 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/27 18:17:33 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_two_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_collecitbles(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (c);
}

void	define_exit_xy(t_data *a)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = a->map.map;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				a->map.exit_y = i;
				a->map.exit_x = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	exit_exists(t_data *a)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = a->map.map;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
