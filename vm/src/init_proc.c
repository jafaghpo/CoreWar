/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 11:54:03 by root              #+#    #+#             */
/*   Updated: 2018/02/05 16:16:51 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_proc	*new_proc(t_uint32 player, t_uint32 pc)
{
	t_proc		*new;

	if (!(new = malloc(sizeof(*new))))
		ft_afferror(ERROR_MALLOC);
	new->pc = pc;
	new->carry = 0;
	ft_bzero(new->reg, REG_NUMBER * 4);
	new->reg[0] = g_champs[player + 1].number;
	new->player = player + 1;
	new->live = 0;
	new->id = player + 1;
	return (new);
}

void	init_proc(t_proc **cycle, int nb)
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
		tmp = op_tab[g_mem[proc->pc]].cycles;
		proc->next = cycle[tmp];
		proc->op = g_mem[proc->pc];
		cycle[tmp] = proc;
		i++;
	}
}
