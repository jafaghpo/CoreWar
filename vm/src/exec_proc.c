/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:04:48 by niragne           #+#    #+#             */
/*   Updated: 2018/01/26 18:07:15 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    exec_proc(t_proc **cycle, t_proc *tmp)
{
    static void     (*f[18])() =
                    {NULL, op_live, op_ld, op_st, op_add, op_sub, op_and, op_or,
                    op_xor, op_zjmp, op_ldi, op_sti, op_fork, op_lld, op_lldi,
                    op_lfork, op_aff, clear_new};
    t_uint8         op;
    t_int32         size;
    t_inst          args[4];
    char            str[CHAT_LINE_SIZE];

    op = tmp->op;
    g_infos[tmp->pc].cursor = 0;
    if (op == 0)
    {
        tmp->pc = (tmp->pc + 1) % MEM_SIZE;
        return ;
    }
    size = get_args(tmp->pc, args, op);
    if (size <= 0)
    {
        tmp->pc = (tmp->pc + -size + 1 + op_tab[op].octal) % MEM_SIZE;
        return ;
    }
    f[op](tmp, args, cycle);
    tmp->pc = (tmp->pc + size + 1 + op_tab[op].octal) % MEM_SIZE;
    if (g_step && op < 17)
    {
        ft_sprintf(str, "[%d] %d %s %u", g_nb_cycle, tmp->id, op_tab[op].inst, tmp->pc);
        add_line_chat(str);
        ft_sprintf(str, "%d", g_id);    
        add_line_chat(str);
        g_pause = 1;
        g_step = 0;
    }
    if (op < 17)
        g_infos[tmp->pc].cursor = 1;
}
