/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 22:51:44 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 00:32:33 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dest;
	unsigned char *str;

	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (n-- > 0)
	{
		*dest = *str;
		if (*dest == (unsigned char)c)
			return (dest + 1);
		dest++;
		str++;
	}
	return (NULL);
}
