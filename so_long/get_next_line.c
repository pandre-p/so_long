/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:22:22 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/27 16:47:03 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	freef(char **text)
{
	char	*temp;
	char	*new_text;

	if (!text || !*text)
		return ;
	temp = ft_strchrb(*text, '\n');
	if (temp == NULL)
	{
		free(*text);
		*text = NULL;
		return ;
	}
	temp++;
	new_text = ft_strdup(temp);
	free(*text);
	*text = new_text;
	if (!(*text))
		return ;
}

char	*writefunc(char **text)
{
	char	*buffer;
	char	*line;
	int		i;
	int		ls;

	if (*text == NULL)
		return (NULL);
	line = ft_strchrb(*text, '\n');
	ls = ft_strlenb(*text) - ft_strlenb(line) + 1;
	buffer = malloc(ls + 1);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < ls)
	{
		buffer[i] = (*text)[i];
		++i;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*buffer;
	char		*line;
	ssize_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	i = readf(fd, buffer, &text);
	free (buffer);
	if ((i == 0 && text == NULL) || i == -1)
		return (NULL);
	line = writefunc(&text);
	freef(&text);
	return (line);
}
/*#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int	a;
	char *line;
	
	a = 7;
    if (argc != 2)
        return (0);
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
		return (0);
	}
	while (a != 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		a--;
	}
    close(fd);
    return 0;
}*/
