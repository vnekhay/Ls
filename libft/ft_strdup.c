/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:25:51 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 00:43:29 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		j;
	char	*dest;

	j = 0;
	while (s1[j] != '\0')
		j++;
	dest = (char*)malloc((sizeof(char) * j) + 1);
	if (dest == NULL)
		return (0);
	j = 0;
	while (s1[j] != '\0')
	{
		dest[j] = s1[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
