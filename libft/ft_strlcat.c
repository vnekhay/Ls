/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:23:14 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 00:31:04 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t res;

	if (ft_strlen(dst) >= size)
		return (ft_strlen((char*)src) + size);
	res = ft_strlen(dst) + ft_strlen(src);
	while (*dst && size--)
		dst++;
	while (size-- > 1 && *src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (res);
}
