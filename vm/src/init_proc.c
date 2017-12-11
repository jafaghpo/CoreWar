/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:54:03 by root              #+#    #+#             */
/*   Updated: 2017/12/06 16:33:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_proc   *new_proc(t_uint32 player, t_uint32 pc)
{
	t_proc		*new;

	if (!(new = malloc(sizeof(*new))))
		ft_afferror(ERROR_MALLOC);
	new->pc = pc;
	new->carry = 0;
    ft_bzero(new->reg, REG_NUMBER * 4);
    new->reg[0] = g_champs[player].number;
	new->player = player;
    new->live = 0;
	new->id = player + 1;
	return (new);
}

void    init_proc(t_proc **cycle, int nb)
{
    t_proc  *proc;
    int     tmp;
    int     step;
    int     i;

    step = MEM_SIZE / nb;
    i = 0;
    while (i < nb)
    {
        proc = new_proc(i, i * step);
        tmp = op_tab[g_mem[proc->pc]].cycles;
        proc->next = cycle[tmp];
        cycle[tmp] = proc;
        i++;
    }
}
