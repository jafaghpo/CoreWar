/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:14:54 by root              #+#    #+#             */
/*   Updated: 2017/12/03 18:35:36 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_st(t_proc *p, t_inst *args)
{
    t_int32 tmp;

    if (args[1].type == IND_CODE)
    {
        tmp = (args[1].value + p->pc) % MEM_SIZE;
        while (tmp < 0)
            tmp += MEM_SIZE;
        put_uint32(p->reg[args[0].value - 1], tmp);
        g_case[(tmp + 0) % MEM_SIZE] = (t_case){121.f / 255.f, 240.f / 255.f, 248.f / 255.f};
        g_case[(tmp + 1) % MEM_SIZE] = (t_case){121.f / 255.f, 240.f / 255.f, 248.f / 255.f};
        g_case[(tmp + 2) % MEM_SIZE] = (t_case){121.f / 255.f, 240.f / 255.f, 248.f / 255.f};
        g_case[(tmp + 3) % MEM_SIZE] = (t_case){121.f / 255.f, 240.f / 255.f, 248.f / 255.f};
    }
    else
        p->reg[args[1].value - 1] = p->reg[args[0].value - 1];
}
