/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:18:48 by root              #+#    #+#             */
/*   Updated: 2017/11/23 17:37:12 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_sti(t_proc *p, t_inst *args)
{
    t_int32 a;
    t_int32 b;
    t_int32 tmp;

    a = get_real_value(args + 1, p);
    b = get_real_value(args + 2, p);
    tmp = ((a + b) % IDX_MOD + p->pc) % MEM_SIZE;
    while (tmp < 0)
        tmp += MEM_SIZE;
    put_uint32(p->reg[args[0].value - 1], tmp);
    ft_printf("TMP %d %d %d %d\n", a, b, p->pc, tmp - p->pc);
    g_player[tmp % MEM_SIZE + 0] = 1;
    g_player[tmp % MEM_SIZE + 1] = 1;
    g_player[tmp % MEM_SIZE + 2] = 1;
    g_player[tmp % MEM_SIZE + 3] = 1;
}