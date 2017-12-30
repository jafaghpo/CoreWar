/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:33 by root              #+#    #+#             */
/*   Updated: 2017/12/16 17:58:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *pf_l(char *format, va_list arg, t_pfflags *flags)
{
    (void)arg;
    if (flags->type == L)
        flags->type = LL;
    else
        flags->type = L;
    return (format + 1);
}