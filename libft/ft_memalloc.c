/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:29:00 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 07:55:23 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *s;

	if (size == 0)
		return (NULL);
	if (size)
	{
		s = (void*)malloc(size);
		if (!s)
			return (NULL);
		ft_bzero(s, size);
		return (s);
	}
	return (NULL);
}
