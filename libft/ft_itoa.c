/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:54:47 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 00:55:49 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_length(int n)
{
	size_t length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char			*ft_itoa(int n)
{
	long long int	number;
	int				length;
	char			*str;

	number = n;
	length = ft_length(number);
	if (!(str = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	if (number < 0)
		number *= -1;
	str[length] = '\0';
	while (length-- > 0)
	{
		str[length] = number % 10 + '0';
		number /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
