/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:20:08 by root              #+#    #+#             */
/*   Updated: 2018/01/09 23:35:39 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_lfork(t_proc *p, t_inst *args, t_proc **procs)
{
    t_proc  *new;
    t_int32 tmp;
    
    tmp = args[0].value + p->pc;
    tmp = tmp % MEM_SIZE + MEM_SIZE * (tmp < 0);
    new = create_proc(p, tmp, g_nb_cycle);
    if (g_mem[new->pc] == 0 || g_mem[new->pc] > 16)
        insert_proc(procs, new, (g_nb_cycle + 1) % 1001);    
    else
        insert_proc(procs, new, (g_nb_cycle + op_tab[g_mem[new->pc]].cycles) % 1001);
}
