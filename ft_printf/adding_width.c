/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:57:05 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 21:57:06 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adding_width(int size, t_params *param)
{
	if (param->zero)
		while (param->width > size++)
			throw_in_buf('0', &param->buff);
	else
		while (param->width > size++)
			throw_in_buf(' ', &param->buff);
}
