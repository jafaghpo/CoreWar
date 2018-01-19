/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:18:48 by root              #+#    #+#             */
/*   Updated: 2018/01/20 00:47:50 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_sti(t_proc *p, t_inst *args)
{
    t_int32 add;

    add = get_real_value(args + 1, p, 0) + get_real_value(args + 2, p, 0);
    add %= IDX_MOD;
    add += p->pc;
    add = add % MEM_SIZE + MEM_SIZE * (add < 0);
    put_uint32(p->reg[args[0].value - 1], add);
    g_color[(add + 0) % MEM_SIZE] = g_champs[p->player].color;
    g_color[(add + 1) % MEM_SIZE] = g_champs[p->player].color;
    g_color[(add + 2) % MEM_SIZE] = g_champs[p->player].color;
    g_color[(add + 3) % MEM_SIZE] = g_champs[p->player].color;
}