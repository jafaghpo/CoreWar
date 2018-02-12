/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:18:48 by root              #+#    #+#             */
/*   Updated: 2018/02/12 14:23:32 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_sti(t_proc *p, t_inst *args, t_proc **procs)
{
	t_int32 add;

	add = get_real_value(args + 1, p, 0) + get_real_value(args + 2, p, 0);
	add %= IDX_MOD;
	add += p->pc;
	add = add % MEM_SIZE + MEM_SIZE * (add < 0);
	put_uint32(p->reg[args[0].value - 1], add);
	g_infos[(add + 0) % MEM_SIZE].player = p->player;
	g_infos[(add + 1) % MEM_SIZE].player = p->player;
	g_infos[(add + 2) % MEM_SIZE].player = p->player;
	g_infos[(add + 3) % MEM_SIZE].player = p->player;
	g_infos[(add + 0) % MEM_SIZE].new = 1;
	g_infos[(add + 1) % MEM_SIZE].new = 1;
	g_infos[(add + 2) % MEM_SIZE].new = 1;
	g_infos[(add + 3) % MEM_SIZE].new = 1;
	add_clear_new(procs, add);
}