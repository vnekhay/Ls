/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:15:24 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/19 21:20:54 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_strjoin_path(char *s1, char *s2)
{
	char	*str;
	char	*pstr;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	pstr = str;
	while (*s1 != '\0')
		*str++ = *s1++;
	*str++ = '/';
	while (*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return (pstr);
}
