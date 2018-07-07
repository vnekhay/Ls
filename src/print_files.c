/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:14:07 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/19 21:48:51 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_struct(t_stat **files)
{
	int		i;

	i = -1;
	while (files[++i])
	{
		free(files[i]->name);
		free(files[i]);
		free(files[i]->pathname);
	}
	free(files);
}

void		print_dir(t_envs params, char *pathname, \
	int isrecursion, int count)
{
	DIR				*dir;
	struct dirent	*dp;
	t_stat			**files;
	int				i;

	if (isrecursion)
		ft_printf("\n%s:\n", pathname);
	if (!(dir = opendir(pathname)))
		return (perror(pathname));
	while ((dp = readdir(dir)) != NULL)
		if (params.a == 1 || (params.a == 0 && dp->d_name[0] != '.'))
			++count;
	closedir(dir);
	files = (t_stat **)malloc(sizeof(t_stat*) * (count + 1));
	parse_print(files, pathname, count, params);
	i = -1;
	if (params.big_r == 1)
	{
		while (files[++i])
			if (S_ISDIR(files[i]->stat.st_mode) && !(files[i]->name[0] \
				== '.' && !files[i]->name[1]) && !(files[i]->name[0] == \
				'.' && files[i]->name[1] == '.' && !files[i]->name[2]))
				print_dir(params, files[i]->pathname, 1, 0);
	}
	free_struct(files);
}

void		print_files(t_envs params, t_stat **files[2])
{
	int		i;

	if (params.l == 1 && params.d == 1)
		print_one_column_files_for_l(files[1], params, 0);
	if (params.l == 0 && params.d == 1)
		print_one_column_files(files[1]);
	if (params.l == 1)
		print_one_column_files_for_l(files[0], params, 0);
	else
		print_one_column_files(files[0]);
	i = 0;
	if (params.d != 1)
	{
		while (files[1][i] != 0)
		{
			print_dir(params, files[1][i]->name, 0, 0);
			i++;
		}
	}
}

void		print_usage(char **argv, int i, int j)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(argv[i][j], 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("usage: ls [-1dflRrat] [file ...]", 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}
