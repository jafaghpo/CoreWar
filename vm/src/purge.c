/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:03:21 by niragne           #+#    #+#             */
/*   Updated: 2018/01/25 22:17:50 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void purge(t_proc **cycle)
{
    t_proc  *tmp;
    t_proc  *tmp2;
    int     i;

    i = 0;
    while (i < NB_CYCLE_MAX)
    {
        tmp2 = NULL;
        tmp = cycle[i];
        while (tmp)
        {
            if (!tmp->live)
            {
                if (!tmp2)
                {
                    cycle[i] = tmp->next;
                    g_infos[tmp->pc].cursor = 0;
                    free(tmp);
                    g_id--;
                    tmp = cycle[i];
                    continue ;
                }
                tmp2->next = tmp->next;
                g_infos[tmp->pc].cursor = 0;
                free(tmp);
                g_id--;
                tmp = tmp2->next;
                continue ;
            }
            tmp->live = 0;
            tmp2 = tmp;
            tmp = tmp->next;
        }
        i++;
    }
}
