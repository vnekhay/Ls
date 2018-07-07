/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:38:13 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 04:27:44 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int j;
	int counter;

	counter = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[counter] != '\0')
	{
		j = 0;
		while (s1[counter + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char*)s1 + counter);
			j++;
		}
		counter++;
	}
	return (0);
}
