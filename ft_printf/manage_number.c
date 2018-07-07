/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:58:23 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:16:34 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		manage_number(t_params *param,\
		uintmax_t number, t_size *somepointer)
{
	char			buf[sizeof(intmax_t) * 8];
	char			*pointer;
	int				len;

	if (param->accuracy >= 0)
		param->zero = 0;
	pointer = &buf[sizeof(intmax_t) * 8 - 1];
	*pointer-- = somepointer->integers[number % somepointer->base];
	while (number /= somepointer->base)
		*pointer-- = somepointer->integers[number % somepointer->base];
	if (*(pointer + 1) == '0' && param->accuracy == 0)
		++pointer;
	len = &buf[sizeof(intmax_t) * 8 - 1] - pointer;
	if (somepointer->base == 8 && param->hash && \
		*(pointer + 1) != '0' && param->accuracy <= len)
		param->accuracy = len + 1;
	manage_number2(param, somepointer, len);
	while (++pointer != &buf[sizeof(intmax_t) * 8])
		throw_in_buf(*pointer, &param->buff);
	if (param->width > 0 && param->minus)
		adding_width(0, param);
}

void		manage_number2(t_params *param, t_size *somepointer, int len)
{
	param->width -= ft_strlen(somepointer->article) + len;
	if (somepointer->flag)
		--param->width;
	if (param->accuracy >= 0 && (param->accuracy -= len) >= 0)
		param->width -= param->accuracy;
	else
		param->accuracy = 0;
	if (param->width > 0 && !param->minus && !param->zero)
		adding_width(0, param);
	if (somepointer->flag)
		throw_in_buf(somepointer->flag, &param->buff);
	while (*somepointer->article)
		throw_in_buf(*somepointer->article++, &param->buff);
	while (param->accuracy-- > 0)
		throw_in_buf('0', &param->buff);
	if (param->width > 0 && param->zero)
		adding_width(0, param);
}
