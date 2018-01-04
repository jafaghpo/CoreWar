/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:19:51 by root              #+#    #+#             */
/*   Updated: 2018/01/04 17:59:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_lldi(t_proc *p, t_inst *args)
{
    p->reg[args[2].value - 1] = get_uint32_mem((t_uint32)((get_real_value(args, p, 0) 
    + get_real_value(args + 1, p, 0)) + p->pc));
    p->carry = !p->reg[args[2].value - 1];
}