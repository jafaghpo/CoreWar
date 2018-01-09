/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:59:59 by root              #+#    #+#             */
/*   Updated: 2017/12/16 17:59:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(char *format, ...)
{
    static int  ouais = 1;
    va_list arg;
    int     done;

    if (ouais)
    {
        atexit(pf_putbuff);
        ouais = 0;
    }
    va_start(arg, format);
    done = ft_vprintf(format, arg);
    va_end(arg);
    return (done);
}