/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:16:34 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/19 21:50:20 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		swap_pointers(void **ptr1, void **ptr2)
{
	void	*temp;

	temp = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = temp;
}

int			partition_time_normal_rev(t_stat **files, int bot, int top)
{
	char	*midname;
	time_t	mid;

	mid = files[(bot + top) / 2]->stat.st_mtimespec.tv_sec;
	midname = ft_strdup(files[(bot + top) / 2]->name);
	while (bot <= top)
	{
		while ((files[bot]->stat.st_mtimespec.tv_sec < mid) ||
				(files[bot]->stat.st_mtimespec.tv_sec == mid &&
				ft_strcmp(files[bot]->name, midname) > 0))
			++bot;
		while ((files[top]->stat.st_mtimespec.tv_sec > mid) ||
				(files[top]->stat.st_mtimespec.tv_sec == mid &&
				ft_strcmp(files[top]->name, midname) < 0))
			--top;
		if (bot <= top)
		{
			swap_pointers((void **)(files + bot), (void **)(files + top));
			++bot;
			--top;
		}
	}
	free(midname);
	return (bot);
}

int			partition_time_normal(t_stat **files, int bot, int top)
{
	char	*midname;
	time_t	mid;

	mid = files[(bot + top) / 2]->stat.st_mtimespec.tv_sec;
	midname = ft_strdup(files[(bot + top) / 2]->name);
	while (bot <= top)
	{
		while ((files[bot]->stat.st_mtimespec.tv_sec > mid) ||
				(files[bot]->stat.st_mtimespec.tv_sec == mid &&
				ft_strcmp(files[bot]->name, midname) < 0))
			++bot;
		while ((files[top]->stat.st_mtimespec.tv_sec < mid) ||
				(files[top]->stat.st_mtimespec.tv_sec == mid &&
				ft_strcmp(files[top]->name, midname) > 0))
			--top;
		if (bot <= top)
		{
			swap_pointers((void **)(files + bot), (void **)(files + top));
			++bot;
			--top;
		}
	}
	free(midname);
	return (bot);
}
