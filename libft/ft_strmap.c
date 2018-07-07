/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 00:20:45 by vnekhay           #+#    #+#             */
/*   Updated: 2017/11/20 00:21:57 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	length;
	size_t	j;
	char	*str;

	length = 0;
	j = 0;
	if (!s && !f)
		return (NULL);
	while (s[length] != '\0')
		length++;
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	while (s[j] != '\0')
	{
		str[j] = f((char)s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
