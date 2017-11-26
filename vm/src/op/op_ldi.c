/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:18:01 by root              #+#    #+#             */
/*   Updated: 2017/11/26 18:04:55 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_ldi(t_proc *p, t_inst *args)
{
    p->reg[args[2].value - 1] = get_uint32_mem((t_uint32)((get_real_value(args, p) 
    + get_real_value(args + 1, p) % IDX_MOD) + p->pc));
    p->carry = !p->reg[args[2].value - 1];
}