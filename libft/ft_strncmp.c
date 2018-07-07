/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:24:27 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 04:31:48 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t j;

	j = 0;
	while (j < n && (s1[j] != '\0' || s2[j] != '\0'))
	{
		if (s1[j] == s2[j])
			j++;
		else
			return ((unsigned char)(s1[j]) - (unsigned char)(s2[j]));
	}
	return (0);
}
