/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:27:34 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 00:46:41 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dst[j] = '\0';
		j++;
	}
	return (dst);
}
