/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 21:57:37 by vnekhay           #+#    #+#             */
/*   Updated: 2018/04/20 22:24:44 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# define BUFFSIZE 42

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <locale.h>

typedef struct		s_buff
{
	char			buf[BUFFSIZE];
	size_t			size;
	size_t			done;
}					t_buff;

typedef enum		e_sas
{
	nothing, length_hh, length_h, length_ll, \
	length_l, length_j, length_z
}					t_sas;

typedef struct		s_size
{
	char			flag;
	int				base;
	char			*article;
	char			*integers;
}					t_size;

typedef struct		s_params
{
	int				zero;
	int				minus;
	int				plus;
	int				width;
	int				space;
	int				hash;
	int				accuracy;
	t_sas			size;
	t_buff			buff;
}					t_params;

typedef void		(*t_manager)(const char *, va_list*, t_params*);
const char			*manage_type(const char *fmt,\
		va_list *argumento, t_params *param);
int					ft_printf(const char *fmt, ...);
void				throw_in_buf(char s, struct s_buff *buff);
void				adding_width(int size, t_params *param);
const char			*hunting_for_flags(const char *fmt,\
		t_params *param);
const char			*hunting_for_width(const char *fmt, \
		va_list *argumento, t_params *param);
const char			*hunting_for_accuracy(const char *fmt,\
		va_list *argumento, t_params *param);
const char			*hunting_for_size(const char *fmt,\
		t_params *param);
void				manage_char(const char *fmt,\
		va_list *argumento, t_params *param);
void				manage_widechar(const char *fmt,\
		va_list *argumento, t_params *param);
void				manage_str(const char *fmt,\
		va_list *argumento, t_params *param);
void				manage_widestr(const char *fmt,\
		va_list *argumento, t_params *param);
void				manage_int(const char *fmt,\
		va_list *argumento, t_params *param);
void				manage_o(const char *fmt,\
		va_list *argumento, t_params *param);
void				manage_u(const char *fmt,\
		va_list *argumento, t_params *param);
void				manage_x(const char *fmt,\
		va_list *argumento, t_params *param);
void				manage_p(const char *fmt,\
		va_list *argumento, t_params *param);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);
size_t				additional_conditions(const char *fmt,\
		va_list *argumento, t_params *param);
const char			*manage_params(const char *fmt,\
		va_list *argumento, t_params *param);
intmax_t			intmax_size(va_list *argumento, enum e_sas *size);
uintmax_t			uintmax_size(va_list *argumento, enum e_sas *size);
t_manager			manager(t_manager slots_to_manage[], int number);
void				put_wide_char(wchar_t s, t_buff *buff);
void				manage_number(t_params *param, uintmax_t\
		number, t_size *somepointer);
void				manage_number2(t_params *param,\
		t_size *somepointer, int len);
size_t				length_widestr(wchar_t *s);
size_t				length_widechar(wchar_t s);
t_params			*set_default_params(t_params *param);

#endif
