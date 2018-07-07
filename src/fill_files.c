/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:15:50 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/19 21:47:27 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			params_checker(t_envs params)
{
	int		i;

	i = 0;
	params.l == 1 ? i = 1 : 0;
	params.a == 1 ? i = 1 : 0;
	params.d == 1 ? i = 1 : 0;
	params.t == 1 ? i = 1 : 0;
	params.big_r == 1 ? i = 1 : 0;
	params.r == 1 ? i = 1 : 0;
	params.one == 1 ? i = 1 : 0;
	params.f == 1 ? i = 1 : 0;
	params.ddef == 1 ? i = 1 : 0;
	return (i);
}

t_envs		fill_dir_files(t_stat **files, char *pathname, \
	int count, t_envs params)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;

	dir = opendir(pathname);
	i = 0;
	while (i < count)
	{
		dp = readdir(dir);
		if (params.a == 0 && (dp->d_name[0] == '.'))
			continue ;
		files[i] = (t_stat *)malloc(sizeof(t_stat));
		files[i]->name = ft_strdup(dp->d_name);
		files[i]->pathname = ft_strjoin_path(pathname, dp->d_name);
		lstat(files[i]->pathname, &files[i]->stat);
		params.total += files[i]->stat.st_blocks;
		++i;
	}
	closedir(dir);
	files[i] = 0;
	return (params);
}

void		fill_files2(t_stat **files[2], char **argv, \
	struct stat mystat, int i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (S_ISDIR(mystat.st_mode))
	{
		files[1][j] = (t_stat *)malloc(sizeof(t_stat));
		files[1][j]->name = argv[i];
		lstat(argv[i], &files[1][j]->stat);
		++j;
	}
	else
	{
		files[0][k] = (t_stat *)malloc(sizeof(t_stat));
		files[0][k]->name = argv[i];
		lstat(argv[i], &files[0][k]->stat);
		++k;
	}
}

void		fill_files(t_stat **files[2], int argc, char **argv, t_envs params)
{
	int			i;
	int			ret;
	struct stat mystat;

	i = -1;
	files[0] = (t_stat **)malloc(sizeof(t_stat*) * argc);
	files[1] = (t_stat **)malloc(sizeof(t_stat*) * argc);
	while (++i < argc)
	{
		files[0][i] = 0;
		files[1][i] = 0;
	}
	i = params_checker(params);
	while (++i < argc)
	{
		ret = lstat(argv[i], &mystat);
		if (ret == -1)
		{
			ft_printf("ls: %s: %s\n", argv[i], strerror(errno));
			continue ;
		}
		fill_files2(files, argv, mystat, i);
	}
}
