/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:58:38 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:18:10 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			manage_str(const char *fmt, va_list *argumento, t_params *param)
{
	size_t	len;
	char	*s;
	size_t	j;

	(void)fmt;
	if (param->size == length_l)
		return (manage_widestr(fmt, argumento, param));
	s = va_arg(*argumento, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (param->accuracy >= 0 && (int)len > param->accuracy)
		len = (size_t)param->accuracy;
	if (param->width && !param->minus)
		adding_width((int)len, param);
	j = 0;
	while (*s && j++ < len)
		throw_in_buf(*s++, &param->buff);
	if (param->width && param->minus)
		adding_width((int)len, param);
}

void			manage_widestr(const char *fmt,\
		va_list *argumento, t_params *param)
{
	size_t	len;
	wchar_t	*s;
	size_t	j;

	(void)fmt;
	j = 0;
	s = va_arg(*argumento, wchar_t *);
	if (!s)
		s = (wchar_t*)L"(null)";
	len = length_widestr(s);
	if (param->accuracy >= 0 && (int)len > param->accuracy)
		len = (size_t)param->accuracy;
	if (param->width && !param->minus)
		adding_width((int)len, param);
	while (*s && (j += length_widechar(*s)) <= len)
		put_wide_char(*s++, &param->buff);
	if (param->width && param->minus)
		adding_width((int)len, param);
}

size_t			length_widestr(wchar_t *s)
{
	size_t j;

	j = 0;
	while (*s)
	{
		if (*s <= 0x7F)
			j += 1;
		else if (*s <= 0x7FF)
			j += 2;
		else if (*s <= 0xFFFF)
			j += 3;
		else if (*s <= 0x1FFFFF)
			j += 4;
		++s;
	}
	return (j);
}

size_t			length_widechar(wchar_t s)
{
	if (s <= 0x7F)
		return (1);
	if (s <= 0x7FF)
		return (2);
	if (s <= 0xFFFF)
		return (3);
	if (s <= 0x1FFFFF)
		return (4);
	return (0);
}
