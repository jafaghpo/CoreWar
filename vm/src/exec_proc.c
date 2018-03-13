/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:04:48 by niragne           #+#    #+#             */
/*   Updated: 2018/03/13 17:41:09 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	(*g_f[18])() =
{
	NULL,
	op_live,
	op_ld,
	op_st,
	op_add,
	op_sub,
	op_and,
	op_or,
	op_xor,
	op_zjmp,
	op_ldi,
	op_sti,
	op_fork,
	op_lld,
	op_lldi,
	op_lfork,
	op_aff,
	clear_new
};

void	exec_proc(t_proc **cycle, t_proc *tmp)
{
	t_uint8			op;
	t_int32			size;
	t_inst			args[4];

	op = tmp->op;
	if (op == 0)
		tmp->pc = (tmp->pc + 1) % MEM_SIZE;
	if (op >= 17)
		g_f[op](tmp, args, cycle);
	if (op == 0 || op >= 17)
		return ;
	size = get_args(tmp->pc, args, op);
	if (size <= 0)
	{
		tmp->pc = (tmp->pc + -size + 1 + g_op_tab[op].octal) % MEM_SIZE;
		return ;
	}
	g_f[op](tmp, args, cycle);
	tmp->pc = (tmp->pc + size + 1 + g_op_tab[op].octal) % MEM_SIZE;
	if (g_step && op < 17)
	{
		g_pause = 1;
		g_step = 0;
	}
}
