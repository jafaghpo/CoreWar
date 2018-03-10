/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:19:08 by root              #+#    #+#             */
/*   Updated: 2018/03/10 16:13:24 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_fork(t_proc *p, t_inst *args, t_proc **procs)
{
	t_proc	*new;
	t_int32	tmp;
	char	str[CHAT_LINE_SIZE];
	int		pos;

	tmp = args[0].value % IDX_MOD + p->pc;
	tmp = tmp % MEM_SIZE + MEM_SIZE * (tmp < 0);
	new = create_proc(p, tmp);
	g_infos[tmp].cursor = 1;
	pos = g_nb_cycle % NB_CYCLE_MAX;
	new->next = procs[pos];
	procs[pos] = new;
	if (!g_flags.visu)
		return ;
	ft_sprintf(str, "[%6d] Process %4d created by player %.20s at index %4d",
		g_nb_cycle, new->id, g_champs[p->player].name, tmp);
	add_line_chat(str);
}
