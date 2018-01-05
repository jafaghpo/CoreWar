/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spf_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:45:17 by root              #+#    #+#             */
/*   Updated: 2018/01/05 15:09:05 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char *buf;
static int  i = 0;

void    spf_init_buff(char *str)
{
    buf = str;
    i = 0;
}

void    spf_buff(char *str, int len)
{
    ft_memcpy(buf + i, str, len);
    i += len;
}
