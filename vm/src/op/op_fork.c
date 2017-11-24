/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:19:08 by root              #+#    #+#             */
/*   Updated: 2017/11/24 17:43:24 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_fork(t_proc *p, t_inst *args, t_int32 nb_cycle, t_proc **procs)
{
    t_proc  *new;
    
    new = create_proc(p, get_mod(get_mod(args[0].value + p->pc, IDX_MOD), MEM_SIZE), nb_cycle);
    insert_proc(procs, new, (nb_cycle + op_tab[g_mem[new->pc]].cycles) % 1001);
}
