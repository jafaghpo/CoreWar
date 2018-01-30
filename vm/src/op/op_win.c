/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:20:01 by niragne           #+#    #+#             */
/*   Updated: 2018/01/30 09:10:22 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_win(t_proc *p, t_inst *args)
{
    t_uint32 i;
    t_uint32 a;
    t_int32 b;
    t_int32 c;

    a = get_real_value(args, p, 1);
    b = get_real_value(args + 1, p, 1);
    c = get_real_value(args + 2, p, 1);
    i = 1;
    if (b == 0xde && c == 0xad)
    {
        while (i <= g_nb_player)
        {
            if (g_champs[i].number == a)
            {
                g_champs[i].live = UINT_MAX;
                g_nb_process = 0;
            }
            i++;
        }
    }
}