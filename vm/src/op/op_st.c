/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:14:54 by root              #+#    #+#             */
/*   Updated: 2018/01/09 23:49:50 by iburel           ###   ########.fr       */
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
        g_color[(tmp + 0) % MEM_SIZE] = (t_case){1.f / 255.f, 223.f / 255.f, 215.f / 255.f};
        g_color[(tmp + 1) % MEM_SIZE] = (t_case){1.f / 255.f, 223.f / 255.f, 215.f / 255.f};
        g_color[(tmp + 2) % MEM_SIZE] = (t_case){1.f / 255.f, 223.f / 255.f, 215.f / 255.f};
        g_color[(tmp + 3) % MEM_SIZE] = (t_case){1.f / 255.f, 223.f / 255.f, 215.f / 255.f};
    }
    else
        p->reg[args[1].value - 1] = p->reg[args[0].value - 1];
}
