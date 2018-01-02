/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:59:59 by root              #+#    #+#             */
/*   Updated: 2018/01/02 15:57:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(char *format, ...)
{
    va_list arg;
    int     done;

    va_start(arg, format);
    done = ft_vprintf(format, arg);
    va_end(arg);
    pf_putbuff();
    return (done);
}