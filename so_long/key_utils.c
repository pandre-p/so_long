/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:10:41 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/29 14:12:40 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up(t_data *data, char **map, int i, int c)
{
	if (map[data->map.player_y - 1][data->map.player_x] != '1')
	{
		if (c == 0 && map[data->map.player_y - 1][data->map.player_x] == 'E')
			on_d(data);
		map[data->map.player_y - 1][data->map.player_x] = 'P';
		map[data->map.player_y][data->map.player_x] = '0';
		i++;
		ft_printf("Number of movements: %d\n", i);
		return (i);
	}
	else
		return (i);
}

int	left(t_data *data, char **map, int i, int c)
{
	if (map[data->map.player_y][data->map.player_x - 1] != '1')
	{
		if (c == 0 && map[data->map.player_y][data->map.player_x - 1] == 'E')
			on_d(data);
		map[data->map.player_y][data->map.player_x - 1] = 'P';
		map[data->map.player_y][data->map.player_x] = '0';
		i++;
		ft_printf("Number of movements: %d\n", i);
		return (i);
	}
	else
		return (i);
}

int	down(t_data *data, char **map, int i, int c)
{
	if (map[data->map.player_y + 1][data->map.player_x] != '1')
	{
		if (c == 0 && map[data->map.player_y + 1][data->map.player_x] == 'E')
			on_d(data);
		map[data->map.player_y + 1][data->map.player_x] = 'P';
		map[data->map.player_y][data->map.player_x] = '0';
		i++;
		ft_printf("Number of movements: %d\n", i);
		return (i);
	}
	else
		return (i);
}

int	right(t_data *data, char **map, int i, int c)
{
	if (map[data->map.player_y][data->map.player_x + 1] != '1')
	{
		if (c == 0 && map[data->map.player_y][data->map.player_x + 1] == 'E')
			on_d(data);
		map[data->map.player_y][data->map.player_x + 1] = 'P';
		map[data->map.player_y][data->map.player_x] = '0';
		i++;
		ft_printf("Number of movements: %d\n", i);
		return (i);
	}
	else
		return (i);
}

char	**exit_check(t_data *data, char **map)
{
	if (!exit_exists(data))
	{
		if (data->map.player_x != data->map.exit_x
			|| data->map.player_y != data->map.exit_y)
		{
			map[data->map.exit_y][data->map.exit_x] = 'E';
			return (map);
		}
		return (map);
	}
	return (map);
}
