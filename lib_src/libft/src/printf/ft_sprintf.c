/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:44:25 by root              #+#    #+#             */
/*   Updated: 2017/12/16 18:00:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_sprintf(char *str, char *format, ...)
{
    va_list arg;
    int     done;

    va_start(arg, format);
    done = ft_vsprintf(str, format, arg);
    va_end(arg);
    return (done);
}