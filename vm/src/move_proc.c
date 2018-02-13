/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:02:27 by iburel            #+#    #+#             */
/*   Updated: 2018/02/13 16:59:33 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_proc(t_proc **cycle, t_proc *tmp)
{
	tmp->op = g_mem[tmp->pc] * (g_mem[tmp->pc] < 17);
	tmp->player = g_infos[tmp->pc].player;
	if (tmp->op == 0)
		insert_proc(cycle, tmp, (g_nb_cycle + 1) % NB_CYCLE_MAX);
	else
		insert_proc(cycle, tmp,
			(g_nb_cycle + op_tab[tmp->op].cycles) % NB_CYCLE_MAX);
}
