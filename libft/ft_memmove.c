/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:39:26 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 04:17:22 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				j;
	unsigned char		*dst;
	unsigned const char *str;

	j = 0;
	dst = (unsigned char *)dest;
	str = (unsigned const char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (dst < str)
	{
		while (j < len)
		{
			dst[j] = str[j];
			j++;
		}
	}
	else if (dst > str)
	{
		while (len-- > 0)
			dst[len] = str[len];
	}
	return (dst);
}
