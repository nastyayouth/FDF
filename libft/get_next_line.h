/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <eestell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:30:31 by eestell           #+#    #+#             */
/*   Updated: 2020/02/24 01:21:08 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# define BUFF_SIZE 10

typedef struct		s_file
{
	char			*f_rest;
	int				f_fd;
	int				status;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
