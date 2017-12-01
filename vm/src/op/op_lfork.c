/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:20:08 by root              #+#    #+#             */
/*   Updated: 2017/12/01 16:42:19 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_lfork(t_proc *p, t_inst *args, t_int32 nb_cycle, t_proc **procs)
{
    t_proc  *new;
    
    new = create_proc(p, (t_uint32)(args[0].value + p->pc) % MEM_SIZE, nb_cycle);
    if (g_mem[new->pc] == 0 || g_mem[new->pc] > 16)
        insert_proc(procs, new, (nb_cycle + 1) % 1001);    
    else
        insert_proc(procs, new, (nb_cycle + op_tab[g_mem[new->pc]].cycles) % 1001);
}
