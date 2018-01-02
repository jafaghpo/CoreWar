/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:47:29 by root              #+#    #+#             */
/*   Updated: 2017/12/16 17:59:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char buf[PF_BUFF_SIZE];
static int  fd = 0;
static int  i = 0;

void    fpf_init_buff(int in_fd)
{
    if (fd != 0 && fd != in_fd)
        fpf_putbuff();
    fd = in_fd;
}

void    fpf_buff(char *str, int len)
{
    if (i + len > PF_BUFF_SIZE)
    {
        write(fd, buf, i);
        i = 0;
    }
    ft_memcpy(buf + i, str, len);
    i += len;
}

void    fpf_putbuff(void)
{
    write(fd, buf, i);
    i = 0;
}