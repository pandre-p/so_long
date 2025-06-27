/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:22:26 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/27 17:25:52 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	readf(int fd, char *buffer, char **text)
{
	int		i;
	char	*s;

	i = 1;
	while (ft_strchrb(*text, '\n') == NULL && i > 0)
	{
		ft_bzerob(buffer, BUFFER_SIZE + 1);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || buffer == NULL)
		{
			free(*text);
			return (*text = NULL, i);
		}
		if (i == 0)
			return (i);
		s = ft_strjoinb(*text, buffer);
		if (!s)
		{
			free(*text);
			return (*text = NULL, -1);
		}
		free(*text);
		*text = s;
	}
	return (i);
}

void	ft_bzerob(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

char	*ft_strjoinb(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*st;
	size_t	i;

	i = 0;
	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlenb(s1);
	if (s2 != NULL)
		len2 = ft_strlenb(s2);
	st = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!st)
		return (NULL);
	while (i++ < len1 && s1[i - 1] != '\0')
		st[i - 1] = s1[i - 1];
	i = 0;
	while (i < len2 && s2[i] != '\0')
	{
		st[len1 + i] = s2[i];
		i++;
	}
	st[len1 + len2] = '\0';
	return (st);
}

char	*ft_strchrb(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
	{
		return ((char *)&s[i]);
	}
	return (0);
}

size_t	ft_strlenb(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
