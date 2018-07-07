/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 07:48:00 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 07:48:11 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		*arr;
	int		j;

	j = 0;
	if (min >= max)
		return (NULL);
	arr = (int*)(malloc(sizeof(*arr) * (max - min)));
	while (min < max)
	{
		arr[j] = min;
		j++;
		min++;
	}
	return (arr);
}
