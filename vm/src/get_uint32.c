/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uint32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:29:26 by root              #+#    #+#             */
/*   Updated: 2017/11/26 17:58:00 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_uint32    get_uint32(t_uint8 *data)
{
    t_uint32    ret;

    ret = data[0];
    ret = (ret << 8) + data[1];
    ret = (ret << 8) + data[2];
    ret = (ret << 8) + data[3];
    return (ret);
}

t_uint32    get_uint32_mem(t_uint32 pc)
{
    t_uint32    ret;

    ret = g_mem[pc + 0];
    ret = (ret << 8) + g_mem[(t_uint32)(pc + 1) % MEM_SIZE];
    ret = (ret << 8) + g_mem[(t_uint32)(pc + 2) % MEM_SIZE];
    ret = (ret << 8) + g_mem[(t_uint32)(pc + 3) % MEM_SIZE];
    return (ret);
}
