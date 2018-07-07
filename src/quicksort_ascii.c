/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:16:22 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/19 21:46:02 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			partition(t_stat **files, int bot, int top, int reverse)
{
	char	*mid;
	t_stat	*temp;

	mid = ft_strdup(files[(bot + top) / 2]->name);
	while (bot <= top)
	{
		while ((!reverse && ft_strcmp(files[bot]->name, mid) < 0)
				|| (reverse && ft_strcmp(files[bot]->name, mid) > 0))
			++bot;
		while ((!reverse && ft_strcmp(files[top]->name, mid) > 0)
				|| (reverse && ft_strcmp(files[top]->name, mid) < 0))
			--top;
		if (bot <= top)
		{
			temp = files[bot];
			files[bot] = files[top];
			files[top] = temp;
			++bot;
			--top;
		}
	}
	free(mid);
	return (bot);
}

void		quicksort_name(t_stat **files, int bot, int top, t_envs params)
{
	int		mid;

	if (bot < top)
	{
		if (params.t == 1 && params.r == 0)
			mid = partition_time_normal(files, bot, top);
		else if (params.r == 1 && params.t == 1)
			mid = partition_time_normal_rev(files, bot, top);
		else
			mid = partition(files, bot, top, params.r);
		quicksort_name(files, bot, mid - 1, params);
		quicksort_name(files, mid, top, params);
	}
}
