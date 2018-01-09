/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:18:48 by root              #+#    #+#             */
/*   Updated: 2018/01/09 22:55:12 by iburel           ###   ########.fr       */
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
    g_case[(tmp + 0) % MEM_SIZE] = (t_case){121.f / 255.f, 240.f / 255.f, 248.f / 255.f};
    g_case[(tmp + 1) % MEM_SIZE] = (t_case){121.f / 255.f, 240.f / 255.f, 248.f / 255.f};
    g_case[(tmp + 2) % MEM_SIZE] = (t_case){121.f / 255.f, 240.f / 255.f, 248.f / 255.f};
    g_case[(tmp + 3) % MEM_SIZE] = (t_case){121.f / 255.f, 240.f / 255.f, 248.f / 255.f};
}