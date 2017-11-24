/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:46:06 by iburel            #+#    #+#             */
/*   Updated: 2017/06/08 14:57:07 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# define BUFF_SIZE 60000

struct	s_gnl
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
};

char	*ft_filetostr(char *file);
int		get_next_line(const int fd, char **line);

#endif
