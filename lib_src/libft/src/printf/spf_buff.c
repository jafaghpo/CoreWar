/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spf_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:45:17 by root              #+#    #+#             */
/*   Updated: 2018/01/09 22:30:08 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char *buf;
static int  i;

void    spf_init_buff(char *str)
{
	i = 0;
    buf = str;
}

void    spf_buff(char *str, int len)
{
    ft_memcpy(buf + i, str, len);
    i += len;
}
