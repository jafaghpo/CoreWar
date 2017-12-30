/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:04:48 by niragne           #+#    #+#             */
/*   Updated: 2017/12/30 15:40:51 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    exec_proc(t_proc **cycle, t_uint32 nb_cycle, t_proc *tmp)
{
    static void     (*f[17])() =
                    {NULL, op_live, op_ld, op_st, op_add, op_sub, op_and, op_or,
                    op_xor, op_zjmp, op_ldi, op_sti, op_fork, op_lld, op_lldi,
                    op_lfork, op_aff};
    t_uint8         op;
    t_int32         size;
    t_inst          args[4];

    op = tmp->op;
    if (op == 0 || op > 16)
    {
        tmp->pc = (tmp->pc + 1) % MEM_SIZE;
        insert_proc(cycle, tmp, (nb_cycle + 1) % 1001);
        return ;
    }
    size = get_args(tmp->pc, args, op);
    if (size <= 0)
    {
        tmp->pc = (tmp->pc + -size + 1 + op_tab[op].octal) % MEM_SIZE;
        tmp->op = g_mem[tmp->pc];
        if (g_mem[tmp->pc] == 0 || g_mem[tmp->pc] > 16)
            insert_proc(cycle, tmp, (nb_cycle + 1) % 1001);
        else
            insert_proc(cycle, tmp, (nb_cycle + op_tab[g_mem[tmp->pc]].cycles) % 1001);
        return ;
    }
    f[op](tmp, args, nb_cycle, cycle);
    tmp->pc = (tmp->pc + size + 1 + op_tab[op].octal) % MEM_SIZE;
    tmp->op = g_mem[tmp->pc];
    //ft_printf("pc %d op %d\n", tmp->pc, tmp->op);
    if (g_mem[tmp->pc] == 0 || g_mem[tmp->pc] > 16)
        insert_proc(cycle, tmp, (nb_cycle + 1) % 1001);
    else
        insert_proc(cycle, tmp, (nb_cycle + op_tab[g_mem[tmp->pc]].cycles) % 1001);
    usleep(24000);
}
