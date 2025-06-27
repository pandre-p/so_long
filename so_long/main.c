/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:40:20 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/29 13:46:34 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char	*map_file)
{
	int	i;

	i = strlen(map_file);
	if (i > 4 && ft_strnstr(map_file, ".ber", i))
	{
		if (ft_strnstr(map_file, ".ber", i) == (map_file + i - 4))
			return (1);
	}
	return (0);
}

void	free_map(char	**map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	textures_init(t_data	*data)
{
	int	i;

	i = 32;
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &i, &i);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &i, &i);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &i, &i);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT, &i, &i);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &i, &i);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.map.map_cheked = NULL;
	if (ac != 2)
		return (ft_printf("Error:Wrong Input\n"), 1);
	if (!(check_file(av[1])))
		return (ft_printf("Error:Wrong file\n"), 1);
	data.map.map_cheked = open_map(av[1]);
	if (data.map.map_cheked == NULL)
		return (1);
	data.map.map = open_map(av[1]);
	if (!(map_checker(data.map.map_cheked)))
		return (free_map(data.map.map_cheked), free_map(data.map.map), 1);
	define_map_xy(&data);
	define_player_xy(&data);
	define_exit_xy(&data);
	data.mlx_ptr = mlx_init();
	textures_init(&data);
	if (!(ft_window(data)))
		return (free_map(data.map.map_cheked), free_map(data.map.map), 1);
	return (0);
}
/*falta norminette: map images, mapcheker*/
