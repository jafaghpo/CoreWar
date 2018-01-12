/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:16:13 by niragne           #+#    #+#             */
/*   Updated: 2018/01/12 16:23:31 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32 get_reg(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal)
{
    t_uint8  i;

    i = 0;
    pc = (pc + 1 + octal) % MEM_SIZE;
    while (i < index)
    {
        pc = (pc + args[i].size) % MEM_SIZE;
        i++;
    }
    if (g_mem[pc] < 1 || g_mem[pc] > REG_NUMBER)
        return (-1);
    return (g_mem[pc]);
}
