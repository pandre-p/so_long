/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:21:08 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/27 18:20:11 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	define_map_xy(t_data *a)
{
	a->map.width = ft_strlen(a->map.map[1]);
	a->map.height = ft_two_strlen(a->map.map);
}

void	define_player_xy(t_data *a)
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
			if (map[i][j] == 'P')
			{
				a->map.player_y = i;
				a->map.player_x = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	destroy_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->textures[i])
		{
			mlx_destroy_image(data->mlx_ptr, data->textures[i]);
			data->textures[i] = NULL;
		}
		i++;
	}
}

int	number_collectivels(char **map)
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
