/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:58:12 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:15:11 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_wide_char(wchar_t s, struct s_buff *buff)
{
	if (s <= 0x7F)
		throw_in_buf(s, buff);
	else if (s <= 0x7FF)
	{
		throw_in_buf((s >> 6) | 0xC0, buff);
		throw_in_buf(((s & 0x3F) | 0x80), buff);
	}
	else if (s <= 0xFFFF)
	{
		throw_in_buf((s >> 12) | 0xE0, buff);
		throw_in_buf(((s >> 6) & 0x3F) | 0x80, buff);
		throw_in_buf((s & 0x3F) | 0x80, buff);
	}
	else if (s <= 0x1FFFFF)
	{
		throw_in_buf(((s >> 18) | 0xF0), buff);
		throw_in_buf(((s >> 12) & 0x3F) | 0x80, buff);
		throw_in_buf(((s >> 6) & 0x3F) | 0x80, buff);
		throw_in_buf((s & 0x3F) | 0x80, buff);
	}
}

void	manage_widechar(const char *fmt, \
		va_list *argumento, t_params *param)
{
	wchar_t	s;
	int		len;

	(void)(fmt);
	s = (wchar_t)va_arg(*argumento, wint_t);
	if (s <= 0x7F)
		len = 1;
	else if (s <= 0x7FF)
		len = 2;
	else if (s <= 0xFFFF)
		len = 3;
	else if (s <= 0x1FFFFF)
		len = 4;
	if (param->width && !param->minus)
		adding_width(len, param);
	put_wide_char(s, &param->buff);
	if (param->width && param->minus)
		adding_width(len, param);
}

void	manage_char(const char *fmt, va_list *argumento, t_params *param)
{
	char	c;

	if (param->size == length_l)
		return (manage_widechar(fmt, argumento, param));
	if (*fmt == '%')
		c = '%';
	else
		c = va_arg(*argumento, int);
	if (param->width && !param->minus)
		adding_width(sizeof(char), param);
	throw_in_buf(c, &param->buff);
	if (param->width && param->minus)
		adding_width(sizeof(char), param);
}
