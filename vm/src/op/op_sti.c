/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:18:48 by root              #+#    #+#             */
/*   Updated: 2018/01/04 14:28:04 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_sti(t_proc *p, t_inst *args)
{
    t_int32 a;
    t_int32 b;
    t_int32 tmp;

    a = get_real_value(args + 1, p, 1);
    b = get_real_value(args + 2, p, 1);
    tmp = ((a + b) % IDX_MOD + p->pc) % MEM_SIZE;
    while (tmp < 0)
        tmp += MEM_SIZE;
    put_uint32(p->reg[args[0].value - 1], tmp);
    g_player[(tmp + 0) % MEM_SIZE] = 1;
    g_player[(tmp + 1) % MEM_SIZE] = 1;
    g_player[(tmp + 2) % MEM_SIZE] = 1;
    g_player[(tmp + 3) % MEM_SIZE] = 1;
}