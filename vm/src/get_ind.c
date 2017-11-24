/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:17:36 by niragne           #+#    #+#             */
/*   Updated: 2017/11/12 19:25:03 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32 get_ind(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal)
{
    t_uint8  i;
    t_int16  ret;
    
    i = 0;
    pc += 1 + octal;
    while (i < index)
    {
        pc += args[i].size;
        i++;
    }
    ret = get_uint16(g_mem + pc);
    return ((t_int16)ret);
}
