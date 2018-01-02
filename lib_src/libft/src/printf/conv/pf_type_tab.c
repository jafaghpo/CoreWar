/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:06:52 by iburel            #+#    #+#             */
/*   Updated: 2017/12/06 22:55:44 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint64    (*g_utype[7])(va_list) = 
{
    pf_ushort,
    pf_u2short,
    pf_ulong,
    pf_u2long,
    pf_uintmax,
    pf_size,
    pf_uint
};

t_int64     (*g_type[7])(va_list) = 
{
    pf_short,
    pf_2short,
    pf_long,
    pf_2long,
    pf_intmax,
    pf_ssize,
    pf_int
};