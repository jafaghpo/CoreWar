/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:21:22 by niragne           #+#    #+#             */
/*   Updated: 2017/12/01 19:21:05 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void        *vm(void *av)
{
    static t_proc   *cycle[1001] = {0};
    t_uint32        nb_cycle;

    init_proc(cycle, ((t_args*)av)->nb_players);
    nb_cycle = 0;
    char buf;
    read(1, &buf, 1);
    while (1)
    {
        usleep(00);
        proc_foreach(cycle, nb_cycle);
        nb_cycle++;
    }
   return (NULL);
}
