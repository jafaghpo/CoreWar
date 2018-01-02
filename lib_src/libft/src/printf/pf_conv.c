/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:00:57 by root              #+#    #+#             */
/*   Updated: 2017/12/16 18:01:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     pf_conv(char **format, va_list arg)
{
    t_pfflags flags;
    (*format)++;
    ft_bzero(&flags, sizeof(flags));
    flags.type = ND;
    *format = pf_tags(*format, arg, &flags);
    return (pf_arg(**format, arg, &flags));
}