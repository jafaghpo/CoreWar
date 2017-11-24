/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:16:13 by niragne           #+#    #+#             */
/*   Updated: 2017/11/12 19:25:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32 get_reg(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal)
{
    t_uint8  i;

    i = 0;
    pc += 1 + octal;
    while (i < index)
    {
        pc += args[i].size;
        i++;
    }
    if (g_mem[pc] < 1 || g_mem[pc] > REG_NUMBER)
        return (-1);
    return (g_mem[pc]);
}
