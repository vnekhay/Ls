/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:12:27 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/19 21:17:23 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_envs		set_params(char **argv, t_envs params, int i, int j)
{
	argv[i][j] == 'l' ? params.l = 1 : 0;
	argv[i][j] == 'R' ? params.big_r = 1 : 0;
	argv[i][j] == 'r' ? params.r = 1 : 0;
	argv[i][j] == 'a' ? params.a = 1 : 0;
	argv[i][j] == 't' ? params.t = 1 : 0;
	argv[i][j] == '1' ? params.one = 1 : 0;
	argv[i][j] == 'd' ? params.d = 1 : 0;
	argv[i][j] == 'f' ? params.a = 1 : 0;
	argv[i][j] == 'f' ? params.f = 1 : 0;
	return (params);
}

int			ft_whereami(char **argv)
{
	int		i;
	int		flag;
	int		final;

	i = 1;
	final = 0;
	while (argv[i])
	{
		if (argv[i][0] != '-')
		{
			flag = 1;
			final = flag;
		}
		i++;
	}
	return (final);
}

int			additional_condition(t_stat **files[2], int argc, \
	char **argv, t_envs params)
{
	int		i;

	i = 0;
	fill_files(files, argc, argv, params);
	print_files(params, files);
	while (files[0][i] != 0)
		free(files[0][i++]);
	i = 0;
	while (files[1][i] != 0)
		free(files[1][i++]);
	free(files[0]);
	free(files[1]);
	return (0);
}

int			main(int argc, char **argv)
{
	t_envs	params;
	int		flag;
	t_stat	**files[2];

	flag = ft_whereami(argv);
	params = (t_envs){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (argc == 2 && (argv[1][0] == '-' && argv[1][1] == '\0'))
	{
		ft_printf("ls: %s: %s\n", argv[1], strerror(2));
		exit(0);
	}
	if (argc > 1 && argv[1][0] == '-' && argv[1][1])
		params = parser(params, argc, argv, 1);
	if (params.d == 1 && flag == 0)
		return (ft_printf(".\n"));
	if (flag == 0)
		print_dir(params, ".", 0, 0);
	else
		additional_condition(files, argc, argv, params);
	return (0);
}
