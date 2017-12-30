/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:40 by root              #+#    #+#             */
/*   Updated: 2017/12/16 17:58:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *pf_plus(char *format, va_list arg, t_pfflags *flags)
{
    (void)arg;
    flags->tags.plus = 1;
    return (format + 1);
}