/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:17:59 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/27 16:40:40 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'
				&& tab[cur.y][cur.x] != '0'
					&& tab[cur.y][cur.x] != 'P'))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin);
}

int	no_lost(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
