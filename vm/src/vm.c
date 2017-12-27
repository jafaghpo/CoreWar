/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:21:22 by niragne           #+#    #+#             */
/*   Updated: 2017/12/27 17:47:02 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void        *vm(void *av)
{
    static t_proc   *cycle[1001] = {0};
    t_uint32        checks;
    t_uint32        last_check;
    t_uint32        nb_cycle;
    char            str[CHAT_LINE_SIZE];

    ft_bzero(str, sizeof(str));
    init_proc(cycle, ((t_args*)av)->nb_players);
    nb_cycle = 0;
    checks = 0;
    last_check = CYCLE_TO_DIE;
    //char buf;
    //read(1, &buf, 1);
    while (g_id)
    {
        if (nb_cycle == last_check)
        {
            purge(cycle);
            if (g_nb_live > NBR_LIVE) 
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
            last_check += g_cycle_to_die;
        }
//      usleep(700);
        proc_foreach(cycle, nb_cycle);
        nb_cycle++;
    }
    ft_printf("LA C FINI MDR\nwinner = %s\n", g_champs[pick_winner()].name);
    printf("fdjkfngiuerhoure");
   return (NULL);
}
