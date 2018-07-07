/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:38:07 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 04:18:38 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				j;
	unsigned const char *str1;
	unsigned const char *str2;

	j = 0;
	str1 = s1;
	str2 = s2;
	while (j < n)
	{
		if (str1[j] == str2[j])
			j++;
		else
			return (str1[j] - str2[j]);
	}
	return (0);
}
