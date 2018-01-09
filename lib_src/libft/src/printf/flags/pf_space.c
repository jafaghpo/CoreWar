/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:58:49 by root              #+#    #+#             */
/*   Updated: 2017/12/16 17:58:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *pf_space(char *format, va_list arg, t_pfflags *flags)
{
    (void)arg;
    flags->tags.space = 1;
    return (format + 1);
}