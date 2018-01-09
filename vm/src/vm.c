/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:21:22 by niragne           #+#    #+#             */
/*   Updated: 2018/01/09 23:22:34 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void        *vm(void *av)
{
    static t_proc   *cycle[1001] = {0};
    t_uint32        checks;
    t_uint32        last_check;

    init_proc(cycle, ((t_args*)av)->nb_players);
    g_nb_cycle = 0;
    checks = 0;
    last_check = CYCLE_TO_DIE;
    if (((t_args*)av)->dump && ((t_args*)av)->dumps == 0)
    {
        debug_map();
        return (NULL);
    }
    while (g_id)
    {
        if (((t_args*)av)->dump && g_nb_cycle == ((t_args*)av)->dumps + 1)
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
        usleep((int)g_sleep);
        proc_foreach(cycle, g_nb_cycle);
        g_nb_cycle++;
    }
    end_game();
    return (NULL);
}
