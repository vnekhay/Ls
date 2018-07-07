/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:57:11 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 21:59:35 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*set_default_params(t_params *param)
{
	param->minus = 0;
	param->zero = 0;
	param->plus = 0;
	param->space = 0;
	param->hash = 0;
	param->width = 0;
	param->accuracy = -1;
	param->size = nothing;
	return (param);
}
