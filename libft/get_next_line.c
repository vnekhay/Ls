/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 03:50:30 by vnekhay           #+#    #+#             */
/*   Updated: 2018/01/18 18:07:00 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*charjoin(char const *dest, char a)
{
	char	*str;
	int		i;
	int		strln;

	if (!dest || !a)
		return (NULL);
	strln = (int)ft_strlen(dest);
	str = ft_strnew(strln + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < strln)
		*(str + i) = *(dest + i);
	*(str + i) = a;
	return (str);
}

int				until_slash_n(char **dest, char *source)
{
	int		i;
	int		count;
	char	*p;

	i = -1;
	count = 0;
	while (source[++i])
		if (source[i] == '\n')
			break ;
	p = *dest;
	if (!(*dest = ft_strnew(i)))
		return (0);
	free(p);
	while (source[count] && count < i)
	{
		p = *dest;
		if (!(*dest = charjoin(*dest, source[count])))
			return (0);
		free(p);
		count++;
	}
	return (i);
}

void			additional_condition(t_list *current, char **line)
{
	int		j;
	char	*p;

	j = until_slash_n(line, current->content);
	p = current->content;
	if (j < (int)ft_strlen(current->content))
	{
		current->content = ft_strsub(current->content, j + 1,
		ft_strlen(current->content));
		free(p);
	}
	else
		ft_strclr(current->content);
}

static t_list	*multiple_fd(int fd, t_list **file)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*file = NULL;
	t_list			*current;
	ssize_t			ret;
	void			*p;

	if ((!line) || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	current = multiple_fd(fd, &file);
	MALLCHECK((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		p = current->content;
		MALLCHECK((current->content = ft_strjoin(current->content, buf)));
		free(p);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(current->content))
		return (0);
	additional_condition(current, line);
	return (1);
}
