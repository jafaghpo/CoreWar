/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_procs_foreach.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:57:18 by iburel            #+#    #+#             */
/*   Updated: 2018/01/11 13:04:04 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    move_procs_foreach(t_proc **cycle)
{
    t_proc      *tmp;
    t_proc      *tmp2;
    int         pos;
    
    pos = g_nb_cycle % 1001;
    tmp = cycle[pos];
    while (tmp)
    {
        tmp2 = tmp->next;
        move_proc(cycle, tmp);
        tmp = tmp2;
    }
    cycle[pos] = NULL;
}