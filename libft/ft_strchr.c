/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:39:10 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 02:31:03 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int j;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == (char)c)
			return ((char *)s + j);
		j++;
	}
	if (s[j] == (char)c)
		return ((char *)s + j);
	return (NULL);
}
