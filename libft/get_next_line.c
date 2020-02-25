/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <eestell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:42:18 by eestell           #+#    #+#             */
/*   Updated: 2019/11/25 23:21:48 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_findchr(const char *str)
{
	int			i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && (str[i] != '\n' || str[i] != '\0'))
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

int					ft_make_line(char **rest, int fd)
{
	int				len_buf;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];

	if (!*rest)
		*rest = ft_strnew(0);
	while (ft_findchr(*rest) < 0)
	{
		len_buf = read(fd, &buf, BUFF_SIZE);
		if (len_buf < 0)
			return (-1);
		buf[len_buf] = '\0';
		if (*rest)
		{
			tmp = ft_strjoin(*rest, buf);
			free(*rest);
			*rest = tmp;
		}
		if (len_buf < 1)
			return (0);
	}
	return (1);
}

int					get_next_line2(const int fd, char **line, char **rest)
{
	int				index_chr;
	int				a;
	char			*tmp;

	if ((a = ft_make_line(rest, fd)) == 0)
	{
		if (ft_strlen(*rest) > 0)
		{
			*line = ft_strdup(*rest);
			free(*rest);
			*rest = NULL;
			return (1);
		}
		*line = *rest;
		return (0);
	}
	index_chr = ft_findchr(*rest);
	if (index_chr >= 0)
	{
		*line = ft_strsub(*rest, 0, index_chr);
		tmp = *rest;
		*rest = ft_strsub(tmp, index_chr + 1, ft_strlen(*rest));
		free(tmp);
	}
	return (a);
}

void				find_ptr(t_file *fd_file, char **line, int fd, int *trh)
{
	t_file			*ptr;
	t_file			*buf;

	ptr = fd_file;
	while (ptr && ptr->status)
	{
		if (ptr->f_fd == fd)
		{
			*trh = get_next_line2(fd, line, &(ptr->f_rest));
			if (trh == 0)
				free(fd_file);
			return ;
		}
		if (ptr->next == NULL)
		{
			buf = (t_file*)malloc(sizeof(t_file));
			ptr->next = buf;
			buf->f_rest = ft_strnew(0);
			buf->f_fd = fd;
			buf->status = 1;
			buf->next = NULL;
		}
		ptr = ptr->next;
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_file	*fd_file = NULL;
	int				trh;

	trh = 0;
	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (!fd_file)
	{
		if (!(fd_file = (t_file*)malloc(sizeof(t_file))))
			return (-1);
		fd_file->f_rest = ft_strnew(0);
		fd_file->f_fd = fd;
		fd_file->next = NULL;
		fd_file->status = 1;
	}
	find_ptr(fd_file, line, fd, &trh);
	return (trh);
}
