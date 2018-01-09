/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:17:08 by root              #+#    #+#             */
/*   Updated: 2017/12/01 16:33:37 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_xor(t_proc *p, t_inst *args)
{
    t_int32 a;
    t_int32 b;

    a = get_real_value(args, p, 1);
    b = get_real_value(args + 1, p, 1);
    p->reg[args[2].value - 1] = a ^ b;
    p->carry = !p->reg[args[2].value - 1];    
}