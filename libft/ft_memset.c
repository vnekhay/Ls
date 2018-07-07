/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <vnekhay@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:39:22 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 04:43:48 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
