/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:41:10 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/27 19:14:08 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./minilibx-linux/mlx.h"
# include "./Lib_ft/libft.h"
# include "./Lib_ft/printf/ft_printf.h"
# include "./minilibx-linux/mlx_int.h"

# define FLOOR "textures/floor.xpm"
# define WALL "textures/wall.xpm"
# define PLAYER "textures/dude.xpm"
# define COLLECT "textures/collectivel.xpm"
# define EXIT "textures/door.xpm"

typedef enum e_exit
{
	FAILURE,
	SUCCESS,
}	t_exit;

typedef struct s_map
{
	char	**map;
	char	**map_cheked;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	t_map	map;
}	t_data;

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

int		map_checker(char **map);
char	*get_next_line(int fd);
void	ft_bzerob(void *s, size_t n);
size_t	ft_strlenb(const char *s);
char	*ft_strjoinb(char const *s1, char const *s2);
char	*ft_strchrb(const char *s, int c);
int		readf(int fd, char *buffer, char **text);
char	**open_map(char *filename);
int		check_is_retangular(char **map);
int		invalid_characters(char	**map);
int		ft_two_strlen(char **str);
int		exit_reachable(char **map);
void	free_map(char **map);
int		get_collecitbles(char **map);
void	flood_fill(char **tab, t_point size, t_point begin);
int		no_lost(char **map);
int		ft_window(t_data a);
void	define_player_xy(t_data *a);
void	define_map_xy(t_data *a);
void	destroy_textures(t_data *data);
void	fill_map(t_data *data);
int		number_collectivels(char **map);
int		on_d(t_data *data);
int		up(t_data *data, char **map, int i, int c);
int		left(t_data *data, char **map, int i, int c);
int		down(t_data *data, char **map, int i, int c);
int		right(t_data *data, char **map, int i, int c);
void	define_exit_xy(t_data *a);
char	**exit_check(t_data *data, char **map);
int		exit_exists(t_data *a);
int		check_walls(char **map);
int		count_elements(char **map, int *c, int *e, int *p);

#endif
