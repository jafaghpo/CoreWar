/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_procs_foreach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:55:44 by niragne           #+#    #+#             */
/*   Updated: 2018/03/13 16:57:34 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_procs_foreach(t_proc **cycle)
{
	t_proc		*tmp;

	tmp = cycle[g_nb_cycle % NB_CYCLE_MAX];
	while (tmp)
	{
		g_infos[tmp->pc].cursor = 0;
		if (tmp->op == 17)
			printf("%d\n", tmp->pc);
		exec_proc(cycle, tmp);
		if (tmp->op < 17)
			g_infos[tmp->pc].cursor = 1;
		while (g_pause)
			;
		tmp = tmp->next;
	}
	while (g_pause)
		;
}
