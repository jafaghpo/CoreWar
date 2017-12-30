/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uintmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:59:35 by root              #+#    #+#             */
/*   Updated: 2017/12/16 17:59:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uint64 pf_uintmax(va_list arg)
{
    t_uint64 n;

    n = va_arg(arg, uintmax_t);
    return (n);
}