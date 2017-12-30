/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:44:59 by root              #+#    #+#             */
/*   Updated: 2017/12/17 19:56:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# define BUFF_SIZE 60000

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_gnl    t_gnl;

struct	s_gnl
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
};

char	*ft_filetostr(char *file);
int		get_next_line(const int fd, char **line);

#endif