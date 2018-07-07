/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:58:17 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:25:35 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		intmax_size(va_list *argumento, enum e_sas *size)
{
	intmax_t	number;

	number = va_arg(*argumento, intmax_t);
	if (number == 4294967296)
		return ((size_t)number);
	if (*size == length_hh)
		return ((signed char)number);
	if (*size == length_h)
		return ((short)number);
	if (*size == length_ll)
		return ((long)number);
	if (*size == length_l)
		return ((long long)number);
	if (*size == length_j)
		return (number);
	if (*size == length_z)
		return ((size_t)number);
	else
		return ((int)number);
}

void			manage_int(const char *fmt, va_list *argumento, t_params *param)
{
	intmax_t	nbr;
	t_size		somepointer;
	uintmax_t	unbr;

	(void)fmt;
	nbr = intmax_size(argumento, &param->size);
	somepointer.flag = '\0';
	if (param->plus)
		somepointer.flag = '+';
	else if (param->space)
		somepointer.flag = ' ';
	if (nbr >= 0)
		unbr = nbr;
	else
	{
		unbr = -nbr;
		somepointer.flag = '-';
	}
	somepointer.article = "";
	somepointer.base = 10;
	somepointer.integers = "0123456789";
	manage_number(param, unbr, &somepointer);
}
