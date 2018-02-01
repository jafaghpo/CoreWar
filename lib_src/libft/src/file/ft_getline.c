/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:19:56 by iburel            #+#    #+#             */
/*   Updated: 2018/02/01 15:23:58 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "mem.h"
#include <stdlib.h>
#include <unistd.h>

int     ft_getline(char **line, t_file *file)
{
    int     size_line;
    char    *tmp;
    int     size;

    if (file->i >= file->len)
    {
        file->len = read(file->fd, file->buf, BUFF_SIZE);
        file->i = 0;
    }
    if (file->len <= 0)
        return (file->len);
    size = file->len - file->i;
    if ((tmp = ft_memchr(file->buf + file->i, '\n', size)))
    {
        size = tmp - file->buf - file->i;
        if (!(*line = malloc(size + 1)))
            return (-1);
        ft_memcpy(*line, file->buf + file->i, size);
        (*line)[size] = '\0';
        file->i += size + 1;
        return (1);
    }
    if (!(*line = malloc(size + 1)))
        return (-1);
    ft_memcpy(*line, file->buf + file->i, size);
    size_line = size;
    while (1)
    {
        if ((file->len = read(file->fd, file->buf, BUFF_SIZE)) == -1)
            return (-1);
        if (file->len == 0)
        {
            (*line)[size_line] = '\0';
            file->i = 0;
            return (1);
        }
        if ((tmp = ft_memchr(file->buf, '\n', file->len)))
        {
            size = tmp - file->buf;
            if (!(*line = realloc(*line, size_line + size + 1)))
                return (-1);
            ft_memcpy(*line + size_line, file->buf, size);
            (*line)[size_line + size] = '\0';
            file->i = size + 1;
            return (1);
        }
        if (!(*line = realloc(*line, size_line + BUFF_SIZE + 1)))
            return (-1);
        ft_memcpy(*line + size_line, file->buf, BUFF_SIZE);
        size_line += BUFF_SIZE;
    }
    return (4);
}