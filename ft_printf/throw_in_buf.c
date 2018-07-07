/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_in_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:58:54 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 21:58:55 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		throw_in_buf(char s, struct s_buff *buff)
{
	buff->buf[buff->size++] = s;
	if (buff->size == BUFFSIZE)
	{
		write(1, buff->buf, buff->size);
		buff->done += buff->size;
		buff->size = 0;
	}
}
