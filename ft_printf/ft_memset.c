/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:57:17 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 21:57:18 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int j;

	j = 0;
	while (len-- > 0)
	{
		*((unsigned char *)b + j) = (unsigned char)c;
		j++;
	}
	return (b);
}
