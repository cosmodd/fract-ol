/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:59:32 by mrattez           #+#    #+#             */
/*   Updated: 2021/10/26 16:13:54 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *s, char c)
{
	size_t	count;
	int		visited;

	count = 0;
	visited = 0;
	while (*s)
	{
		if (*s != c && !visited)
			count++;
		visited = *s != c;
		s++;
	}
	return (count);
}

static char	*ft_extract_word(char *s, char c)
{
	int		word_len;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	return (ft_substr(s, 0, word_len));
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	char	*str;
	size_t	tabsize;
	int		visited;
	int		i;

	str = (char *)s;
	tabsize = ft_count_words(str, c);
	tab = malloc((tabsize + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	visited = 0;
	i = 0;
	while (*str)
	{
		if (*str != c && !visited)
		{
			tab[i] = ft_extract_word(str, c);
			i++;
		}
		visited = *str != c;
		str++;
	}
	tab[tabsize] = 0;
	return (tab);
}
