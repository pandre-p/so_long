/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:41:12 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/29 14:11:24 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_xy_collectibles(t_point a, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				a.x = j;
				a.y = i;
				return (a);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (a);
}

int	exit_reachable(char **map)
{
	t_point	a;
	t_point	b;

	a.x = 0;
	b.x = ft_strlen(map[0]);
	b.y = ft_two_strlen(map);
	a = get_xy_collectibles(a, map);
	flood_fill(map, b, a);
	if (!(no_lost(map)))
		return (0);
	return (1);
}

int	check_is_retangular(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		while (map[j])
		{
			if (ft_strlen(map[i]) != ft_strlen(map[j]))
				return (ft_printf("Error:Map is not retangular\n"), 0);
			j++;
		}
		j = 0;
		i++;
	}
	if (i < 3)
		return (ft_printf("Error:Map is invalid\n"), 0);
	return (1);
}

int	invalid_characters(char **map)
{
	int	c;
	int	e;
	int	p;

	c = 0;
	e = 0;
	p = 0;
	if (!check_walls(map))
		return (0);
	if (!count_elements(map, &c, &e, &p))
		return (0);
	if (p != 1 || c < 1 || e != 1)
		return (ft_printf("Error:Map is invalid\n"), 0);
	return (1);
}

int	map_checker(char **map)
{
	if (!(check_is_retangular(map)))
		return (0);
	if (!(invalid_characters(map)))
		return (0);
	if (!(exit_reachable(map)))
		return (ft_printf("Error:Exit or collectible aren't reachable\n"), 0);
	return (1);
}
