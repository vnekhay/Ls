/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:01:45 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 00:52:05 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	massive_size(char const *s, char c)
{
	size_t counter;
	size_t words;

	counter = 0;
	words = 0;
	while (s[counter] != '\0')
	{
		while (s[counter] == c)
			counter++;
		while (s[counter] != c && s[counter] != '\0')
		{
			if (s[counter + 1] == c || s[counter + 1] == '\0')
				words++;
			counter++;
		}
	}
	return (words);
}

static	size_t	length(char const *s, char c)
{
	size_t counter;

	counter = 0;
	while (s[counter] != c && s[counter] != '\0')
		counter++;
	return (counter);
}

static	void	ft_free(char **s, size_t j)
{
	while (j)
		free(s[j--]);
	free(s[j]);
	free(s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	j;
	size_t	k;

	j = 0;
	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * massive_size(s, c) + 1)))
		return (NULL);
	while (massive_size(s, c) > 0)
	{
		k = 0;
		while (*s == c)
			s++;
		if (!(split[j] = (char *)malloc(sizeof(char) * length(s, c) + 1)))
		{
			ft_free(split, j);
			return (NULL);
		}
		while (*s != '\0' && *s != c)
			split[j][k++] = *s++;
		split[j++][k] = '\0';
	}
	split[j] = 0;
	return (split);
}
