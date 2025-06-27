/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:41:18 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/27 18:39:25 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_d(t_data *data)
{
	destroy_textures(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data->map.map_cheked);
	free_map(data->map.map);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	char			**map;
	int				c;
	static int		i;

	(void)data;
	map = data->map.map;
	c = number_collectivels(map);
	if (keysym == 65307)
		on_d(data);
	if (keysym == 119)
		i = up(data, map, i, c);
	if (keysym == 97)
		i = left(data, map, i, c);
	if (keysym == 115)
		i = down(data, map, i, c);
	if (keysym == 100)
		i = right(data, map, i, c);
	define_player_xy(data);
	data->map.map = exit_check(data, map);
	fill_map(data);
	return (0);
}

void	put_image(int y, int x, void *a, t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, a, x, y);
}

void	fill_map(t_data *data)
{
	int		j;
	int		i;
	char	**map;

	j = -1;
	map = data->map.map;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0')
				put_image(j * 32, i * 32, data->textures[0], data);
			if (map[j][i] == 'E')
				put_image(j * 32, i * 32, data->textures[4], data);
			if (map[j][i] == '1')
				put_image(j * 32, i * 32, data->textures[1], data);
			if (map[j][i] == 'C')
				put_image(j * 32, i * 32, data->textures[3], data);
			if (map[j][i] == 'P')
				put_image(j * 32, i * 32, data->textures[2], data);
		}
	}
}

int	ft_window(t_data a)
{
	if (!a.mlx_ptr)
		return (0);
	a.win_ptr = mlx_new_window(a.mlx_ptr, a.map.width * 32,
			a.map.height * 32, ":D");
	if (!a.win_ptr)
		return (free(a.mlx_ptr), 0);
	fill_map(&a);
	mlx_hook(a.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &a);
	mlx_hook(a.win_ptr, DestroyNotify, StructureNotifyMask, &on_d, &a);
	mlx_loop(a.mlx_ptr);
	return (1);
}
