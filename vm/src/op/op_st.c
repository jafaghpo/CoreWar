/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:14:54 by root              #+#    #+#             */
/*   Updated: 2018/02/12 14:23:19 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_st(t_proc *p, t_inst *args, t_proc **procs)
{
	t_int32 tmp;

	if (args[1].type == IND_CODE)
	{
		tmp = args[1].value + p->pc;
		tmp = tmp % MEM_SIZE + MEM_SIZE * (tmp < 0);
		put_uint32(p->reg[args[0].value - 1], tmp);
		g_infos[(tmp + 0) % MEM_SIZE].player = p->player;
		g_infos[(tmp + 1) % MEM_SIZE].player = p->player;
		g_infos[(tmp + 2) % MEM_SIZE].player = p->player;
		g_infos[(tmp + 3) % MEM_SIZE].player = p->player;
		g_infos[(tmp + 0) % MEM_SIZE].new = 1;
		g_infos[(tmp + 1) % MEM_SIZE].new = 1;
		g_infos[(tmp + 2) % MEM_SIZE].new = 1;
		g_infos[(tmp + 3) % MEM_SIZE].new = 1;
		add_clear_new(procs, tmp);
	}
	else
		p->reg[args[1].value - 1] = p->reg[args[0].value - 1];
}
