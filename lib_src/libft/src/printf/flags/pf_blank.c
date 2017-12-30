/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_blank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:20 by root              #+#    #+#             */
/*   Updated: 2017/12/16 17:58:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *pf_blank(char *format, va_list arg, t_pfflags *flags)
{
    int     n;

    (void)arg;
    n = 0;
    while (*format >= '0' && *format <= '9')
    {
        n = n * 10 + *format - '0';
        format++;
    }
    flags->blank = n;
    return (format);
}