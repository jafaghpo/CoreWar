/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:21:22 by niragne           #+#    #+#             */
/*   Updated: 2018/02/13 01:39:46 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*static void	check_process()
{
	
}*/

void		*vm(void *av)
{
	static t_proc	*cycle[NB_CYCLE_MAX] = {0};
	t_uint32		checks;
	t_uint32		last_check;
	Uint32			start;
	Uint32			end;
	Uint32			diff;

	init_proc(cycle, ((t_args*)av)->nb_players);
	checks = 0;
	last_check = CYCLE_TO_DIE;
	while (g_nb_process)
	{
		start = SDL_GetTicks();
		if (((t_args*)av)->dump && g_nb_cycle == ((t_args*)av)->dumps)
		{
			debug_map();
			return (NULL);
		}
		if (g_nb_cycle == last_check)
		{
			purge(cycle);
			if (g_nb_live >= NBR_LIVE)
			{
				g_cycle_to_die -= CYCLE_DELTA;
				checks = 0;
			}
			else if (checks >= MAX_CHECKS)
			{
				g_cycle_to_die -= CYCLE_DELTA;
				checks = 0;
			}
			g_nb_live = 0;
			checks++;
			last_check += (g_cycle_to_die - 1) * (g_cycle_to_die >= 0) + 1;
		}
		exec_procs_foreach(cycle);
		move_procs_foreach(cycle);
		end = SDL_GetTicks();
		diff = end - start;
		if (diff < (Uint32)g_sleep)
			usleep((Uint32)g_sleep - diff);
		g_nb_cycle++;
	}
	end_game();
	return (NULL);
}
