/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:56:29 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 04:06:28 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int j;

	j = 0;
	while (s[j] != '\0')
		j++;
	if (c == '\0')
		return ((char *)s + j);
	while (j >= 0)
	{
		if (s[j] == (char)c)
			return ((char *)s + j);
		j--;
	}
	return (NULL);
}
