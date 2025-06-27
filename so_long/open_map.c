/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:24:00 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/29 13:50:06 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_free(char *str1, char *str2)
{
	char	*buffer;

	buffer = ft_strjoin(str1, str2);
	free(str1);
	return (buffer);
}

char	**open_map(char *filename)
{
	int		fd;
	char	*line;
	char	*map;
	char	**final_map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: Could not open file\n"), NULL);
	map = get_next_line(fd);
	if (!map)
		return (ft_printf("Error: Empty file\n"), close(fd), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin_free(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	final_map = ft_split(map, '\n');
	free(map);
	if (final_map == NULL)
		return (ft_printf("Error: Map empty\n"), NULL);
	return (final_map);
}

int	count_elements(char **map, int *c, int *e, int *p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				(*e)++;
			if (map[i][j] == 'P')
				(*p)++;
			if (map[i][j] == 'C')
				(*c)++;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (ft_printf("Invalid character: %c\n", map[i][j]), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' || map[ft_two_strlen(map) - 1][j] != '1')
				return (ft_printf("Map is not surrounded by walls\n"), 0);
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (ft_printf("Map is not surrounded by walls\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
