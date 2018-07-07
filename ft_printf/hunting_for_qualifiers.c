/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hunting_for_qualifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:58:04 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:14:09 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*hunting_for_flags(const char *fmt, t_params *param)
{
	if (*fmt == '-')
		param->minus = 1;
	else if (*fmt == '0')
		param->zero = 1;
	else if (*fmt == '+')
		param->plus = 1;
	else if (*fmt == ' ')
		param->space = 1;
	else if (*fmt == '#')
		param->hash = 1;
	if (param->minus)
		param->zero = 0;
	++fmt;
	return (fmt);
}

const char	*hunting_for_width(const char *fmt,\
		va_list *argumento, t_params *param)
{
	if (*fmt == '*')
	{
		param->width = va_arg(*argumento, int);
		if (param->width < 0)
		{
			param->minus = 1;
			param->width = -param->width;
		}
		++fmt;
	}
	else
	{
		param->width = 0;
		while (ft_isdigit(*fmt))
			param->width = param->width * 10 + (*fmt++ - '0');
	}
	return (fmt);
}

const char	*hunting_for_accuracy(const char *fmt,\
		va_list *argumento, t_params *param)
{
	if (*++fmt == '*')
	{
		param->accuracy = va_arg(*argumento, int);
		if (param->accuracy < 0)
			param->accuracy = -1;
		++fmt;
	}
	else
	{
		param->accuracy = 0;
		while (ft_isdigit(*fmt))
			param->accuracy = param->accuracy * 10 + (*fmt++ - '0');
	}
	return (fmt);
}

const char	*hunting_for_size(const char *fmt, t_params *param)
{
	while (*fmt && ft_strchr("hljz", *fmt))
	{
		if (*fmt == 'h' && *(fmt + 1) == 'h')
		{
			param->size = length_hh;
			++fmt;
		}
		else if (*fmt == 'l' && *(fmt + 1) == 'l')
		{
			param->size = length_ll;
			++fmt;
		}
		else if (*fmt == 'h')
			param->size = length_h;
		else if (*fmt == 'l')
			param->size = length_l;
		else if (*fmt == 'j')
			param->size = length_j;
		else if (*fmt == 'z')
			param->size = length_z;
		++fmt;
	}
	return (fmt);
}
