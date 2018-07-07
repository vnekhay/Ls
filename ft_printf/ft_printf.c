/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:57:31 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:01:01 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*manage_params(const char *fmt, va_list *argumento, t_params *param)
{
	while (*fmt)
	{
		if (ft_strchr("-0+ #", *fmt))
			fmt = hunting_for_flags(fmt, param);
		else if (*fmt == '*' || ft_isdigit(*fmt))
			fmt = hunting_for_width(fmt, argumento, param);
		else if (*fmt == '.')
			fmt = hunting_for_accuracy(fmt, argumento, param);
		else if (ft_strchr("hljz", *fmt))
			fmt = hunting_for_size(fmt, param);
		else
			break ;
	}
	fmt = manage_type(fmt, argumento, param);
	return (fmt);
}

size_t		additional_conditions(const char *fmt, \
		va_list *argumento, t_params *param)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			set_default_params(param);
			fmt = manage_params(++fmt, argumento, param);
		}
		else
			throw_in_buf(*fmt++, &param->buff);
	}
	write(1, param->buff.buf, param->buff.size);
	param->buff.done += param->buff.size;
	param->buff.size = 0;
	return (param->buff.done);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		argumento;
	t_params	param;
	int			finish;

	if (!fmt || BUFFSIZE <= 0)
		return (-1);
	va_start(argumento, fmt);
	ft_memset(&param, 0, sizeof(param));
	finish = (int)additional_conditions(fmt, &argumento, &param);
	return (finish);
}
