/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_procs_foreach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:55:44 by niragne           #+#    #+#             */
/*   Updated: 2018/02/05 14:38:17 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_procs_foreach(t_proc **cycle)
{
	t_proc		*tmp;

	tmp = cycle[g_nb_cycle % NB_CYCLE_MAX];
	while (tmp)
	{
		exec_proc(cycle, tmp);
		while (g_pause)
			;
		tmp = tmp->next;
	}
	while (g_pause)
		;
}
