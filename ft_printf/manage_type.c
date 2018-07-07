/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:58:46 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:20:20 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_manager			manager(t_manager slots_to_manage[], int number)
{
	slots_to_manage[0] = &manage_str;
	slots_to_manage[1] = &manage_widestr;
	slots_to_manage[2] = &manage_p;
	slots_to_manage[3] = &manage_int;
	slots_to_manage[4] = &manage_int;
	slots_to_manage[5] = &manage_int;
	slots_to_manage[6] = &manage_o;
	slots_to_manage[7] = &manage_o;
	slots_to_manage[8] = &manage_u;
	slots_to_manage[9] = &manage_u;
	slots_to_manage[10] = &manage_x;
	slots_to_manage[11] = &manage_x;
	slots_to_manage[12] = &manage_char;
	slots_to_manage[13] = &manage_widechar;
	slots_to_manage[14] = &manage_char;
	return (slots_to_manage[number]);
}

const char			*manage_type(const char *fmt, \
		va_list *argumento, t_params *param)
{
	const char	*type_chr;
	t_manager	slots_to_manage[15];
	const char	type_str[] = "sSpdDioOuUxXcC%";
	t_manager	managehelper;

	if (*fmt)
	{
		if ((type_chr = ft_strchr(type_str, *fmt)))
		{
			if (ft_strchr("DOUCS", *fmt))
				param->size = length_l;
			managehelper = manager(slots_to_manage, type_chr - type_str);
			managehelper(fmt, argumento, param);
		}
		else
		{
			if (param->width && !param->minus)
				adding_width(sizeof(char), param);
			throw_in_buf(*fmt, &param->buff);
			if (param->width && param->minus)
				adding_width(sizeof(char), param);
		}
		++fmt;
	}
	return (fmt);
}
