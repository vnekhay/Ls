/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:13:43 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 02:23:21 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dest;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	while (n-- > 0)
		*dest++ = *(unsigned char *)src++;
	return (dst);
}
