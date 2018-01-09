/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:47:29 by root              #+#    #+#             */
/*   Updated: 2017/12/16 18:00:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char buf[PF_BUFF_SIZE];
static int  i = 0;

void    pf_buff(char *str, int len)
{
    if (i + len > PF_BUFF_SIZE)
    {
        write(1, buf, i);
        i = 0;
    }
    ft_memcpy(buf + i, str, len);
    i += len;
}

void    pf_putbuff(void)
{
    write(1, buf, i);
    i = 0;
}