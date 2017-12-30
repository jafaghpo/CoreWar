/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spf_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:45:17 by root              #+#    #+#             */
/*   Updated: 2017/12/16 18:02:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char *buf;
static int  i = 0;

void    spf_init_buff(char *str)
{
    buf = str;
}

void    spf_buff(char *str, int len)
{
    ft_memcpy(buf + i, str, len);
    i += len;
}