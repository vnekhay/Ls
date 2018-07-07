/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:35:10 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 03:20:00 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(size_t number, int flag)
{
	if (number >= 9223372036854775807 && flag == 1)
		return (-1);
	else if (number > 9223372036854775807 && flag == -1)
		return (0);
	else
		return ((int)number * flag);
}

int			ft_atoi(const char *str)
{
	int		j;
	size_t	number;
	int		flag;

	j = 0;
	number = 0;
	flag = 1;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j++;
	if (str[j] == '+')
		j++;
	else if (str[j] == '-')
	{
		j++;
		flag = -1;
	}
	while (str[j] != '\0')
	{
		if (str[j] >= '0' && str[j] <= '9')
			number = number * 10 + (str[j] - '0');
		else
			break ;
		j++;
	}
	return (ft_check(number, flag));
}
