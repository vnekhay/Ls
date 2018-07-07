/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:25:22 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/19 22:22:43 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include "libft.h"
# include <stdio.h>
# include <sys/stat.h>
# include <errno.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <limits.h>
# define PATH_MAX        1024
# define USAGELRR   argv[i][j] != 'l' &&argv[i][j] != 'R' && argv[i][j] != 'r'
# define USAGEAT1   argv[i][j] != 'a' && argv[i][j] != 't' && argv[i][j] != '1'
# define USAGEDF    argv[i][j] != 'd' && argv[i][j] != 'f'
# define MAJOR(x) (int32_t)(((uint32_t)(x) >> 24) & 0xff)
# define MINOR(x) (uint32_t)((x) & 0xffffff)

typedef	struct		s_stat
{
	struct stat		stat;
	char			*name;
	char			*pathname;
}					t_stat;

typedef struct		s_envs
{
	int				big_r;
	int				r;
	int				a;
	int				l;
	int				t;
	int				one;
	int				f;
	int				d;
	int				total;
	int				ddef;
}					t_envs;

int					additional_condition(t_stat **files[2], int argc, \
	char **argv, t_envs params);
int					ft_whereami(char **argv);
t_envs				parser(t_envs params, int argc, char **argv, int i);
t_envs				set_params(char **argv, t_envs params, int i, int j);
void				print_usage(char **argv, int i, int j);
void				print_files(t_envs params, t_stat **files[2]);
void				print_dir(t_envs params, char *pathname, \
	int isrecursion, int count);
void				parse_print(t_stat **files, char *pathname, \
	int count, t_envs params);
void				free_struct(t_stat **files);
t_envs				fill_dir_files(t_stat **files, char *pathname, \
	int count, t_envs params);
void				print_one_column_files(t_stat **files);
void				print_one_column_files_for_l(t_stat **files, \
	t_envs params, int i);
void				print_l_conditions(t_stat **files, int i);
void				print_l_conditions2(t_stat **files, int i);
void				print_l_conditions3(t_stat **files, int i);
char				*ft_strjoin_path(char *s1, char *s2);
void				fill_files(t_stat **files[2], int argc, \
	char **argv, t_envs params);
void				fill_files2(t_stat **files[2], char **argv, \
	struct stat mystat, int i);
int					params_checker(t_envs params);
void				quicksort_name(t_stat **files, int bot, \
	int top, t_envs params);
int					partition_time_normal(t_stat **files, int bot, int top);
int					partition_time_normal_rev(t_stat **files, int bot, int top);
int					partition(t_stat **files, int bot, int top, int reverse);
void				swap_pointers(void **ptr1, void **ptr2);

#endif
