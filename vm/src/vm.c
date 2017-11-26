/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:21:22 by niragne           #+#    #+#             */
/*   Updated: 2017/11/26 14:57:05 by iburel           ###   ########.fr       */
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
    t_uint32        nb_cycle;
    t_proc          *tmp;
    t_inst          args[4];
    t_int32         size;
    t_uint8         op;
	t_args			*flags;

	flags = (t_args *)av;
    init_proc(cycle, flags->nb_players);

#ifdef DEBUG
    debug_cycle(cycle);
#endif

    nb_cycle = 0;
    char buf[2];
    read(1, buf, 1);
    while (1)
    {
		tmp = cycle[nb_cycle % 1001];
        while (tmp)
        {
            op = g_mem[tmp->pc];
            if (nb_cycle - tmp->live > g_cycle_to_die)
            {
                ft_printf("t mor\n");
                remove_proc(tmp);
            }
            else if (op <= 0 || op > 16)
            {
                tmp->pc++;
                tmp->pc %= MEM_SIZE;
                insert_proc(cycle, tmp, (nb_cycle + 1) % 1001);
            }
            else
            {
                size = get_args(tmp->pc, args, op);
                if (size < 0)
                {
                    tmp->pc += -size;
                    tmp->pc %= MEM_SIZE;
                    ft_printf("%d\n", tmp->pc);
                    insert_proc(cycle, tmp, (nb_cycle + op_tab[g_mem[tmp->pc]].cycles) % 1001);
                }
                else
                {
                    #ifdef DEBUG
                        debug_inst(args, tmp->pc, op);
                    #endif
                    f[op](tmp, args, nb_cycle, cycle);
                    ft_printf("cycle %d\n", nb_cycle);
                    ft_printf("increment %d %d\n", size, op_tab[op].octal);
                    ft_printf("INST: %s\n", op_tab[op].inst);
                    tmp->pc += size + 1 + op_tab[op].octal;
                    tmp->pc %= MEM_SIZE;
                    debug_proc(tmp);
                    insert_proc(cycle, tmp, (nb_cycle + op_tab[g_mem[tmp->pc]].cycles) % 1001);
                    //usleep(300000);
                    g_player[tmp->pc] = 0;
                    read(1, buf, 1);
                    g_player[tmp->pc] = 1;
                    system("clear");
                    debug_map();
                }
            }
            tmp = tmp->next;
            cycle[nb_cycle % 1001] = tmp;
        }
        nb_cycle++;
    }
	return (NULL);
}
