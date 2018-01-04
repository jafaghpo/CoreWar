/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:21:22 by niragne           #+#    #+#             */
/*   Updated: 2018/01/03 14:37:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_uint32     g_cycle_to_die = CYCLE_TO_DIE;

void        *vm(void *av)
{
    static void     (*f[17])() =
                    {NULL, op_live, op_ld, op_st, op_add, op_sub, op_and, op_or,
                    op_xor, op_zjmp, op_ldi, op_sti, op_fork, op_lld, op_lldi,
                    op_lfork, op_aff};
    static t_proc   *cycle[1001] = {0};
    t_uint32        g_nb_cycle;
    t_proc          *tmp;
    t_inst          args[4];
    t_int32         size;
    t_uint8         op;
    t_args			*flags;
    t_proc          *tmp2;

	flags = (t_args *)av;
    init_proc(cycle, flags->nb_players);

#ifdef DEBUG
    debug_cycle(cycle);
#endif

    g_nb_cycle = 0;
    char buf[2];
    read(1, buf, 1);
    while (1)
    {
        usleep(300);
        tmp = cycle[g_nb_cycle % 1001];
        while (tmp)
        {
            g_player[tmp->pc] = 1;    
            tmp2 = tmp->next;
            tmp->reg[0] = 0xdeadbeef;
            op = g_mem[tmp->pc];
            if (g_nb_cycle - tmp->live > g_cycle_to_die)
            {
                ft_printf("t mor %d %d\n", g_nb_cycle , tmp->live);
                remove_proc(tmp);
            }
            else if (op <= 0 || op > 16)
            {
                tmp->pc++;
                tmp->pc %= MEM_SIZE;
                insert_proc(cycle, tmp, (g_nb_cycle + 1) % 1001);
            }
            else
            {
                size = get_args(tmp->pc, args, op);
                if (size <= 0)
                {
                    tmp->pc += -size + 1 + op_tab[op].octal;
                    tmp->pc %= MEM_SIZE;
                    insert_proc(cycle, tmp, (g_nb_cycle + op_tab[g_mem[tmp->pc]].cycles) % 1001);
                }
                else
                {
                    #ifdef DEBUG
                    //debug_inst(args, tmp->pc, op);
                    #endif
                    f[op](tmp, args, g_nb_cycle, cycle);
                    //ft_printf("cycle %d\n", g_nb_cycle);                    
                    //ft_printf("increment %d %d\n", size, op_tab[op].octal);
                    //ft_printf("INST: %s\n", op_tab[op].inst);
                    tmp->pc += size + 1 + op_tab[op].octal;
                    tmp->pc %= MEM_SIZE;
                    //debug_proc(tmp);
                    if (g_mem[tmp->pc] == 0 || g_mem[tmp->pc] > 16)
                        insert_proc(cycle, tmp, (g_nb_cycle + 1) % 1001);
                    else
                        insert_proc(cycle, tmp, (g_nb_cycle + op_tab[g_mem[tmp->pc]].cycles) % 1001);
                    //system("clear");
                    //debug_map();
                }
            }
            tmp = tmp2;
            cycle[g_nb_cycle % 1001] = tmp;
        }
        g_nb_cycle++;
        //read(1, buf, 1);
    }
	return (NULL);
}
