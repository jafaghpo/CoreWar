/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_procs_foreach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:57:18 by iburel            #+#    #+#             */
/*   Updated: 2018/03/10 14:14:30 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_procs_foreach(t_proc **cycle)
{
	t_proc		*tmp;
	t_proc		*tmp2;
	int			pos;

	pos = g_nb_cycle % NB_CYCLE_MAX;
	tmp = cycle[pos];
	while (tmp)
	{
		if (tmp->op >= 17)
		{
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
			continue ;
		}
		tmp2 = tmp->next;
		move_proc(cycle, tmp);
		tmp = tmp2;
	}
	cycle[pos] = NULL;
}
