/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:40:47 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 04:31:02 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t j;
	size_t k;

	j = 0;
	k = 0;
	if (s2 == NULL & s1 == NULL)
		return (NULL);
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[j] != '\0' && j < n)
	{
		k = 0;
		while (s1[j + k] == s2[k] && (j + k) < n)
		{
			if (s2[k + 1] == '\0')
				return ((char *)s1 + j);
			k++;
		}
		j++;
	}
	return (NULL);
}
