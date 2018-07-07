/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:13:17 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 02:57:09 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	j;
	size_t	slen;
	char	*cps;

	j = 0;
	len = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	if (j != slen)
		while (s[slen - 1] == ' ' || s[slen - 1] == '\n' || s[slen - 1] == '\t')
			slen--;
	cps = (char *)malloc(sizeof(char) * (slen - j + 1));
	if (!cps)
		return (NULL);
	while (j < slen)
		cps[len++] = s[j++];
	cps[len] = '\0';
	return (cps);
}
