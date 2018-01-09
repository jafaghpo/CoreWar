/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:44:25 by root              #+#    #+#             */
/*   Updated: 2017/12/17 12:34:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_fprintf(int fd, char *format, ...)
{
    static int ouais = 1;
    va_list arg;
    int     done;

    if (ouais)
    {
        atexit(fpf_putbuff);
        ouais = 0;
    }
    va_start(arg, format);
    done = ft_vfprintf(fd, format, arg);
    va_end(arg);
    return (done);
}