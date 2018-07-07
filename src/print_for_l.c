/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:13:00 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/19 21:51:30 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_l_conditions3(t_stat **files, int i)
{
	if ((S_ISGID & files[i]->stat.st_mode) == S_ISGID)
		(S_IXGRP & files[i]->stat.st_mode) == \
	S_IXGRP ? ft_printf("s") : ft_printf("S");
	else
		(S_IXGRP & files[i]->stat.st_mode) == \
		S_IXGRP ? ft_printf("x") : ft_printf("-");
	(S_IROTH & files[i]->stat.st_mode) == \
	S_IROTH ? ft_printf("r") : ft_printf("-");
	(S_IWOTH & files[i]->stat.st_mode) == \
	S_IWOTH ? ft_printf("w") : ft_printf("-");
	if ((S_ISVTX & files[i]->stat.st_mode) == \
	S_ISVTX)
		(S_IXOTH & files[i]->stat.st_mode) == \
		S_IXOTH ? ft_printf("t") : ft_printf("T");
	else
		(S_IXOTH & files[i]->stat.st_mode) == \
		S_IXOTH ? ft_printf("x") : ft_printf("-");
}

void		print_l_conditions2(t_stat **files, int i)
{
	if ((files[i]->stat.st_mode))
		(S_IRUSR & files[i]->stat.st_mode) == \
		S_IRUSR ? ft_printf("r") : ft_printf("-");
	(S_IWUSR & files[i]->stat.st_mode) == \
	S_IWUSR ? ft_printf("w") : ft_printf("-");
	if ((S_ISUID & files[i]->stat.st_mode) == S_ISUID)
		(S_IXUSR & files[i]->stat.st_mode) == \
		S_IXUSR ? ft_printf("s") : ft_printf("S");
	else
		(S_IXUSR & files[i]->stat.st_mode) == \
		S_IXUSR ? ft_printf("x") : ft_printf("-");
	(S_IRGRP & files[i]->stat.st_mode) == \
	S_IRGRP ? ft_printf("r") : ft_printf("-");
	(S_IWGRP & files[i]->stat.st_mode) == \
	S_IWGRP ? ft_printf("w") : ft_printf("-");
	print_l_conditions3(files, i);
}

void		print_l_conditions(t_stat **files, int i)
{
	if (S_ISFIFO(files[i]->stat.st_mode))
		ft_printf("p");
	else if (S_ISCHR(files[i]->stat.st_mode))
		ft_printf("c");
	else if (S_ISDIR(files[i]->stat.st_mode))
		ft_printf("d");
	else if (S_ISBLK(files[i]->stat.st_mode))
		ft_printf("b");
	else if (S_ISREG(files[i]->stat.st_mode))
		ft_printf("-");
	else if (S_ISLNK(files[i]->stat.st_mode))
		ft_printf("l");
	else if (S_ISSOCK(files[i]->stat.st_mode))
		ft_printf("s");
	else if (S_ISSOCK(files[i]->stat.st_mode))
		ft_printf("s");
	print_l_conditions2(files, i);
}

void		print_one_column_files_for_l(t_stat **files, t_envs params, int i)
{
	char	path[PATH_MAX];

	(params.d == 0) ? ft_printf("total %d\n", params.total) : 0;
	while (files[i] != 0)
	{
		print_l_conditions(files, i);
		ft_printf(" %d", files[i]->stat.st_nlink);
		ft_printf(" %s", getpwuid(files[i]->stat.st_uid)->pw_name);
		ft_printf(" %s", getgrgid(files[i]->stat.st_gid)->gr_name);
		if (S_ISCHR(files[i]->stat.st_mode) || S_ISBLK(files[i]->stat.st_mode))
			ft_printf(" %d, %d", MAJOR(files[i]->stat.st_rdev), \
					MINOR(files[i]->stat.st_rdev));
		else
			ft_printf(" %d", files[i]->stat.st_size);
		ft_printf(" %.12s", ctime(&files[i]->stat.st_mtimespec.tv_sec) + 4);
		ft_printf(" %s", files[i]->name);
		if (S_ISLNK(files[i]->stat.st_mode))
		{
			readlink(files[i]->pathname, path, PATH_MAX);
			ft_printf(" -> %s\n", path);
		}
		else
			ft_printf("\n");
		++i;
	}
}

void		print_one_column_files(t_stat **files)
{
	int		i;

	i = 0;
	while (files[i] != 0)
		ft_printf("%s\n", files[i++]->name);
}
