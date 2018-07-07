/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:14:29 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/20 14:49:59 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		parse_print(t_stat **files, char *pathname, \
	int count, t_envs params)
{
	params = fill_dir_files(files, pathname, count, params);
	(params.f == 0) ? \
	quicksort_name(files, 0, count - 1, params) : NULL;
	(params.l == 1) ? \
	print_one_column_files_for_l(files, params, 0) : \
	print_one_column_files(files);
}

t_envs		parser(t_envs params, int argc, char **argv, int i)
{
	int		j;

	(argv[1][0] == '-' && argv[1][1] == '-') ? params.ddef = 1 : 0;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] != '-')
			return (params);
		if ((argv[1][0] == '-' && argv[i][0]) || \
			(argv[1][0] == '-' && argv[1][1] == '-'))
		{
			while (argv[i][0] == '-' && argv[i][1] != '-' && argv[i][j])
			{
				params = set_params(argv, params, i, j);
				(USAGELRR && USAGEAT1 && USAGEDF) ? print_usage(argv, i, j) : 0;
				j++;
			}
			if (params.ddef == 1 && argv[1][2])
				print_usage(argv, i, j);
			if (params.ddef == 1 && argv[2] && argv[2][0] == '-')
				print_usage(argv, i, j);
		}
		i++;
	}
	return (params);
}
