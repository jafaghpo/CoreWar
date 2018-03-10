/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:54:03 by root              #+#    #+#             */
/*   Updated: 2018/03/10 14:01:50 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define REGNUMBER REG_NUMBER

static t_proc	*new_proc(t_uint32 player, t_uint32 pc)
{
	t_proc		*new;

	if (!(new = malloc(sizeof(*new))))
		ft_afferror(ERROR_MALLOC"\n");
	new->pc = pc;
	new->carry = 0;
	ft_bzero(new->reg, REGNUMBER * 4);
	new->reg[0] = g_champs[player + 1].number;
	new->player = player + 1;
	new->live = 0;
	new->id = player + 1;
	return (new);
}

void			init_proc(t_proc **cycle, int nb)
{
	t_proc	*proc;
	int		tmp;
	int		step;
	int		i;

	step = MEM_SIZE / nb;
	i = 0;
	while (i < nb)
	{
		proc = new_proc(i, i * step);
		tmp = g_op_tab[g_mem[proc->pc]].cycles;
		proc->next = cycle[tmp];
		proc->op = g_mem[proc->pc];
		cycle[tmp] = proc;
		i++;
	}
}

#undef REGNUMBER
