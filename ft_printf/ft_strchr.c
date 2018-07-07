/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:57:45 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 21:57:46 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
