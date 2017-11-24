/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:17:06 by niragne           #+#    #+#             */
/*   Updated: 2017/11/13 14:37:01 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32 get_dir(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal)
{
    t_uint8  i;
    t_int32  ret;
    
    i = 0;
    pc += 1 + octal;
    while (i < index)
    {
        pc += args[i].size;
        i++;
    }
    if (args[i].size == 4)
        ret = (t_int32)get_uint32(g_mem + pc);
    else
        ret = (t_int16)get_uint16(g_mem + pc);
    return (ret);
}
