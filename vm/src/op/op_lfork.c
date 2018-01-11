/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:20:08 by root              #+#    #+#             */
/*   Updated: 2018/01/11 11:35:21 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_lfork(t_proc *p, t_inst *args, t_proc **procs)
{
    t_proc  *new;
    t_int32 tmp;
    char    str[CHAT_LINE_SIZE];
    int     pos;
    
    tmp = (args[0].value + p->pc);
    tmp = tmp % MEM_SIZE + MEM_SIZE * (tmp < 0);
    new = create_proc(p, tmp, g_nb_cycle);
    pos = g_nb_cycle % 1001;
    new->next = procs[pos];
    procs[pos] = new;
    ft_sprintf(str, "[%6d] Process %4d created by player %.15s at index %4d", g_nb_cycle, new->id, g_champs[p->player].name, new->pc);
    add_line_chat(str);
}
