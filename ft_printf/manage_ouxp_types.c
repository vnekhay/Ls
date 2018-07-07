/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ouxp_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:58:30 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:25:56 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		uintmax_size(va_list *argumento, enum e_sas *size)
{
	uintmax_t	num;

	num = va_arg(*argumento, uintmax_t);
	if (*size == length_hh)
		return ((unsigned char)num);
	if (*size == length_h)
		return ((unsigned short)num);
	if (*size == length_ll)
		return ((unsigned long)num);
	if (*size == length_l)
		return ((unsigned long long)num);
	if (*size == length_j)
		return (num);
	if (*size == length_z)
		return ((size_t)num);
	else
		return ((unsigned int)num);
}

void			manage_o(const char *fmt, va_list *argumento, t_params *param)
{
	uintmax_t	unbr;
	t_size		somepointer;

	(void)fmt;
	unbr = uintmax_size(argumento, &param->size);
	somepointer.flag = '\0';
	somepointer.article = "";
	somepointer.base = 8;
	somepointer.integers = "01234567";
	manage_number(param, unbr, &somepointer);
}

void			manage_u(const char *fmt, va_list *argumento, t_params *param)
{
	uintmax_t	unbr;
	t_size		somepointer;

	(void)fmt;
	unbr = uintmax_size(argumento, &param->size);
	somepointer.flag = '\0';
	somepointer.article = "";
	somepointer.base = 10;
	somepointer.integers = "0123456789";
	manage_number(param, unbr, &somepointer);
}

void			manage_x(const char *fmt, va_list *argumento, t_params *param)
{
	uintmax_t	unbr;
	t_size		somepointer;

	unbr = uintmax_size(argumento, &param->size);
	somepointer.flag = '\0';
	if (unbr && param->hash)
	{
		if (*fmt == 'X')
			somepointer.article = "0X";
		else
			somepointer.article = "0x";
	}
	else
		somepointer.article = "";
	if (*fmt == 'X')
		somepointer.integers = "0123456789ABCDEF";
	else
		somepointer.integers = "0123456789abcdef";
	somepointer.base = 16;
	manage_number(param, unbr, &somepointer);
}

void			manage_p(const char *fmt, va_list *argumento, t_params *param)
{
	uintmax_t	unbr;
	t_size		somepointer;

	(void)fmt;
	unbr = (uintmax_t)va_arg(*argumento, void *);
	somepointer.flag = '\0';
	somepointer.article = "0x";
	somepointer.integers = "0123456789abcdef";
	somepointer.base = 16;
	manage_number(param, unbr, &somepointer);
}
