/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:33:18 by ppassos           #+#    #+#             */
/*   Updated: 2024/05/22 13:37:34 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_words(char **words, size_t count)
{
	while (count > 0)
	{
		free(words[count - 1]);
		count--;
	}
	free(words);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	c_w;

	c_w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			c_w++;
		i++;
	}
	return (c_w);
}

static char	**ft_part2(char const *s, size_t w_n, char c, char **words)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			words[w_n] = ft_substr(s, start, i - start);
			if (!words[w_n])
			{
				free_words(words, w_n);
				return (NULL);
			}
			w_n++;
		}
		else
			i++;
	}
	words[w_n] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	w_mn;
	size_t	w_n;
	char	**words;

	w_n = 0;
	if (s == NULL)
		return (NULL);
	w_mn = ft_countwords(s, c);
	words = malloc((w_mn + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	if (w_mn == 0)
	{
		words[0] = NULL;
		return (words);
	}
	return (ft_part2(s, w_n, c, words));
}
/*int     main(void)
{
	int i = 0;
	char c = 32;
	char **tabstr;
	
	tabstr = ft_split("hello!", c);
	printf("%s", tabstr[i]);
	return (0);
}*/
/*int     main(void)
{
        char c = 'a';
        size_t c_w;
        
        c_w = ft_countwords("", c);
        printf("%zu", c_w);
        return (0);
}*/
